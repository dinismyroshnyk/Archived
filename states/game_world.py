import pygame, os, pytmx
from states.state import State
from player import Player
from states.pause_screen import PauseScreen

class GameWorld(State):
    def __init__(self, game):
        State.__init__(self, game)
        self.tmxdata = pytmx.load_pygame(os.path.join(self.game.assets_dir, 'map', 'mapa.tmx'))
        #self.grass_img = pygame.transform.scale(pygame.image.load(os.path.join(self.game.assets_dir, 'map', 'grass.png')).convert(), self.game.GAME_LOGIC_SIZE)
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
        #surface.blit(self.grass_img, (0, 0))
        self.draw_map(surface)
        self.player.render(surface)

    def draw_map(self, surface):
        tmxdata = self.tmxdata
        for layer in tmxdata.visible_layers:
            if isinstance(layer, pytmx.TiledTileLayer):
                for x, y, gid in layer:
                    tile = tmxdata.get_tile_image_by_gid(gid)
                    if tile:
                        surface.blit(tile, (x * tmxdata.tilewidth, y * tmxdata.tileheight))