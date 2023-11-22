import pygame, os

class Player():
    def __init__(self, game):
        self.game = game
        self.load_sprites()
        self.pos = (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 2) # posiçao do jogador 
        self.curr_frame, self.last_frame_update = 0, 0

    def update(self, dt, keys):
        direction_x = keys['RIGHT'] - keys['LEFT']
        direction_y = keys['DOWN'] - keys['UP']
        vel = 300
        normalized_direction = pygame.math.Vector2(direction_x, direction_y)
        if normalized_direction.length(): normalized_direction = normalized_direction.normalize()
        self.pos = (self.pos[0] + normalized_direction.x * vel * dt, self.pos[1] + normalized_direction.y * vel * dt)
        self.animate(dt, direction_x, direction_y)

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