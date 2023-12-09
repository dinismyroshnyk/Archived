import pygame, os
from states.state import State
from player import Player
from states.pause_screen import PauseScreen

class GameWorld(State):
    def __init__(self, game):
        State.__init__(self, game)
        self.grass_img = pygame.transform.scale(pygame.image.load(os.path.join(self.game.assets_dir, 'map', 'grass.png')).convert(), self.game.GAME_LOGIC_SIZE)
        self.player = Player(self.game)
        self.game.player = self.player

    def update(self, dt, keys):
        self.player.update(dt, keys)
        if keys['PAUSE']:
            new_state = PauseScreen(self.game)
            new_state.enter_state()
        if keys['ARROW_UP']:
            self.player.client.send_data('switch_up')
        if keys['ARROW_DOWN']:
            self.player.client.send_data('switch_down')

    def render(self, surface):
        surface.blit(self.grass_img, (0, 0))
        self.player.render(surface)