import pygame, os
from states.state import State
from player import Player

class GameWorld(State):
    def __init__(self, game):
        State.__init__(self, game)
        self.grass_img = pygame.transform.scale(pygame.image.load(os.path.join(self.game.assets_dir, 'map', 'grass.png')).convert(), self.game.GAME_LOGIC_SIZE)
        self.player = Player(self.game)

    def update(self, dt, keys):
        self.player.update(dt, keys)

    def render(self, surface):
        surface.blit(self.grass_img, (0, 0))
        self.player.render(surface)