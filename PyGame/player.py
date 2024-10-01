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
        self.is_host = False
        self.client = Client()
        self.client.run()

    def update(self, dt, keys):
        self.chars = self.client.chars
        direction_x = keys['RIGHT'] - keys['LEFT']
        direction_y = keys['DOWN'] - keys['UP']
        self.vel = 300
        normalized_direction = pygame.math.Vector2(direction_x, direction_y)
        self.curr_char = next((i for i, character in enumerate(self.chars) if character['controlled'] and character['assigned_to'] is not None), 0)
        if normalized_direction.length(): 
            normalized_direction = normalized_direction.normalize()
            self.new_pos = (self.chars[self.curr_char]['position'][0] + normalized_direction.x * self.vel * dt, self.chars[self.curr_char]['position'][1] + normalized_direction.y * self.vel * dt)
            if 0 <= self.new_pos[0] <= self.game.GAME_LOGIC_SIZE[0] - self.scaled_width and 0 <= self.new_pos[1] <= self.game.GAME_LOGIC_SIZE[1] - self.scaled_height:
                self.chars[self.curr_char]['position'] = self.new_pos
                self.update_party(dt)
        if self.client.connected:
            self.update_server()
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
        for i, char in enumerate(self.chars):
            sprite = self.curr_sprite.copy()
            shade_color = ((i + 1) * 50, (i + 1) * 50, (i + 1) * 50, 255)
            sprite.fill(shade_color, special_flags=pygame.BLEND_RGBA_MULT)
            surface.blit(sprite, char['position'])

    def animate(self, dt, direction_x, direction_y):
        self.last_frame_update += dt
        if not (direction_x or direction_y):
            self.curr_sprite = self.sprites['down'][0]
            return
        direction = self.get_direction(direction_x, direction_y)
        self.curr_sprite_list = self.sprites[direction]
        if self.last_frame_update > .1:
            self.last_frame_update = 0
            self.curr_frame = (self.curr_frame + 1) % len(self.curr_sprite_list)
            self.curr_sprite = self.curr_sprite_list[self.curr_frame]

    def get_direction(self, direction_x, direction_y):
        if direction_x == 1 and direction_y == 0:
            return 'right'
        elif direction_x == -1 and direction_y == 0:
            return 'left'
        elif direction_x == 0 and direction_y == 1:
            return 'down'
        elif direction_x == 0 and direction_y == -1:
            return 'up'
        elif direction_x == 1 and direction_y == 1:
            return 'down_right'
        elif direction_x == -1 and direction_y == 1:
            return 'down_left'
        elif direction_x == 1 and direction_y == -1:
            return 'up_right'
        elif direction_x == -1 and direction_y == -1:
            return 'up_left'
        else: return 'down'

    def load_sprites(self):
        self.spritesheet = pygame.image.load(os.path.join(self.game.sprites_dir, 'entities', 'player', 'knight', 'Knight_Move.png')).convert_alpha()
        self.frame_width = 52
        self.frame_height = 52
        self.scaled_width = 128
        self.scaled_height = 128
        self.directions = ['down', 'down_right', 'right', 'up_right', 'up', 'up_left', 'left', 'down_left']
        self.sprites = {direction: [] for direction in self.directions}
        for i, direction in enumerate(self.directions):
            for j in range(4):
                frame = self.spritesheet.subsurface(pygame.Rect(j * self.frame_width, i * self.frame_height, self.frame_width, self.frame_height))
                scaled_frame = pygame.transform.scale(frame, (self.scaled_width, self.scaled_height))
                self.sprites[direction].append(scaled_frame)
        self.curr_sprite = self.sprites['down'][0]

    def get_client_id(self):
        for char in self.chars:
            if char['assigned_to'] is not None:
                return char['assigned_to']