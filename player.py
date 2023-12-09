import pygame, os
from server.client import Client

class Player():
    def __init__(self, game):
        self.game = game
        self.load_sprites()
        self.pos = (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 2)
        self.curr_frame, self.last_frame_update = 0, 0
        self.chars = [{'position': (self.pos[0], self.pos[1] + i * 60), 'assigned_to': None, 'controlled': False} for i in range(4)]
        self.curr_char = 0
        self.client = Client()
        self.client.run()

    def update(self, dt, keys):
        direction_x = keys['RIGHT'] - keys['LEFT']
        direction_y = keys['DOWN'] - keys['UP']
        vel = 300
        normalized_direction = pygame.math.Vector2(direction_x, direction_y)
        if normalized_direction.length(): normalized_direction = normalized_direction.normalize()
        self.pos = (self.pos[0] + normalized_direction.x * vel * dt, self.pos[1] + normalized_direction.y * vel * dt)
        self.update_party(dt)
        self.animate(dt, direction_x, direction_y)

    def update_party(self, dt):
        client_id = self.get_client_id()
        assigned_chars = sorted([char for char in self.chars if char['assigned_to'] == client_id], key=lambda x: x['controlled'], reverse=True)
        for i in range(1, len(assigned_chars)):
            direction_to_prev = pygame.math.Vector2(assigned_chars[i - 1]['position']) - pygame.math.Vector2(assigned_chars[i]['position'])
            if direction_to_prev.length() > 60:
                direction_to_prev = direction_to_prev.normalize()
                assigned_chars[i]['position'] = pygame.math.Vector2(assigned_chars[i]['position']) + direction_to_prev * (self.vel * dt)

    def update_server(self):
        if self.chars:
            chars_without_vector2 = [{'controlled': char['controlled'], 'position': tuple(char['position']), 'assigned_to': char['assigned_to']} for char in self.chars]
            self.client.send_data(chars_without_vector2)

    def render(self, surface):
        surface.blit(self.curr_sprite, self.pos)

    def animate(self, dt, direction_x, direction_y):
        self.last_frame_update += dt
        if not (direction_x or direction_y):
            self.curr_sprite = self.curr_sprite_list[0]
            return
        self.curr_sprite_list = self.get_sprite_list(direction_x, direction_y)
        if self.last_frame_update > .1:
            self.last_frame_update = 0
            self.curr_frame = (self.curr_frame + 1) % len(self.curr_sprite_list)
            self.curr_sprite = self.curr_sprite_list[self.curr_frame]

    def get_sprite_list(self, direction_x, direction_y):
        if direction_x and direction_y: return self.get_diagonal_sprite_list(direction_x, direction_y)
        if direction_x: return self.get_horizontal_sprite_list(direction_x)
        if direction_y: return self.get_vertical_sprite_list(direction_y)
        return self.curr_sprite_list
    
    def get_diagonal_sprite_list(self, direction_x, direction_y):
        sprite_map = {
            (1, 1): self.down_right_sprites,
            (-1, 1): self.down_left_sprites,
            (1, -1): self.up_right_sprites,
            (-1, -1): self.up_left_sprites,
        }
        return sprite_map.get((direction_x, direction_y))

    def get_horizontal_sprite_list(self, direction_x):
        sprite_map = {
            1: self.right_sprites,
            -1: self.left_sprites,
        }
        return sprite_map.get(direction_x)

    def get_vertical_sprite_list(self, direction_y):
        sprite_map = {
            1: self.down_sprites,
            -1: self.up_sprites,
        }
        return sprite_map.get(direction_y)

    def load_sprites(self):
        self.sprites_dir = os.path.join(self.game.sprites_dir, 'entities', 'player', 'Base Character')
        self.up_sprites, self.down_sprites, self.left_sprites, self.right_sprites = [], [], [], []
        self.up_right_sprites, self.down_right_sprites, self.up_left_sprites, self.down_left_sprites = [], [], [], []
        sprite_lists = {
            'player_up_': self.up_sprites,
            'player_down_': self.down_sprites,
            'player_left_': self.left_sprites,
            'player_right_': self.right_sprites,
            'player_up_left_': self.up_left_sprites,
            'player_up_right_': self.up_right_sprites,
            'player_down_left_': self.down_left_sprites,
            'player_down_right_': self.down_right_sprites
        }
        for sprite_name, sprite_list in sprite_lists.items():
            for i in range(1, 4):
                sprite = pygame.image.load(os.path.join(self.sprites_dir, sprite_name + str(i) + '.png')).convert_alpha()
                sprite_list.append(sprite)
        self.curr_sprite = self.down_sprites[0]
        self.curr_sprite_list = self.down_sprites

    def get_client_id(self):
        for char in self.chars:
            if char['assigned_to'] is not None:
                return char['assigned_to']