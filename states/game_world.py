import pygame, os, pytmx
from states.state import State
from player import Player
from states.pause_screen import PauseScreen

class GameWorld(State):
    def __init__(self, game):
        State.__init__(self, game)
        self.tmxdata = pytmx.load_pygame(os.path.join(self.game.assets_dir, 'map', 'mapa.tmx'))
        self.player = Player(self.game)
        self.game.player = self.player
        self.arrow_up_pressed = False
        self.arrow_down_pressed = False

    def update(self, dt, keys):
        self.player.update(dt, keys)
        if keys['PAUSE']:
            new_state = PauseScreen(self.game)
            new_state.enter_state()
        if keys['ARROW_UP']:
            if not self.arrow_up_pressed:
                self.player.client.send_data('switch_up')
                self.arrow_up_pressed = True
        else: self.arrow_up_pressed = False
        if keys['ARROW_DOWN']:
            if not self.arrow_down_pressed:
                self.player.client.send_data('switch_down')
                self.arrow_down_pressed = True
        else: self.arrow_down_pressed = False

    def render(self, surface):
        surface.fill((0, 0, 0))
        self.draw_map(surface, 720, 3800, 2.5 * self.tmxdata.tilewidth, 2.5 * self.tmxdata.tileheight)
        self.player.render(surface)

    def draw_map(self, surface, offset_x, offset_y, scale_x, scale_y):
        tmxdata = self.tmxdata
        for layer in tmxdata.visible_layers:
            if isinstance(layer, pytmx.TiledTileLayer):
                for x, y, gid in layer:
                    tile = tmxdata.get_tile_image_by_gid(gid)
                    if tile:
                        tile = pygame.transform.scale(tile, (scale_x, scale_y))
                        surface.blit(tile, ((x * scale_x) - offset_x, (y * scale_y) - offset_y))