import threading
from server.server import Server, run_server
from states.state import State
from states.game_world import GameWorld
from states.credits_screen import CreditsScreen
from states.options_screen import OptionsScreen
from states.multiplayer_screen import MultiplayerScreen

class TitleScreen(State):
    def __init__(self, game):
        State.__init__(self, game)
        self.menu_options = {0: 'Single Player', 1: 'Multiplayer', 2: 'Options', 3: 'Credits', 4: 'Exit'}
        self.menu_cursor = 0

    def update(self, dt, keys):
        self.update_cursor(keys)
        if keys['SELECT']:
            selected_option = self.menu_options[self.menu_cursor]
            self.handle_selected_option(selected_option)
        self.game.reset_keys()

    def handle_selected_option(self, option):
        if option == 'Single Player':
            self.game.server = Server(self.game.GAME_LOGIC_SIZE, max_clients=1)
            server_thread = threading.Thread(target=run_server, args=(self.game.server,))
            server_thread.start()
            new_state = GameWorld(self.game)
            self.game.player.is_host = True
            new_state.enter_state()
        if option == 'Multiplayer':
            new_state = MultiplayerScreen(self.game)
            new_state.enter_state()
        if option == 'Options':
            new_state = OptionsScreen(self.game)
            new_state.enter_state()
        if option == 'Credits':
            new_state = CreditsScreen(self.game)
            new_state.enter_state()
        if option == 'Exit':
            self.game.running, self.game.playing = False, False

    def render(self, surface):
        surface.fill(self.game.colors['BLACK'])
        self.game.draw_text(surface, 'Title Screen', self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 4))
        self.game.draw_text(surface, 'Single Player', self.game.colors['GRAY'] if self.menu_cursor != 0 else self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3))
        self.game.draw_text(surface, 'Multiplayer', self.game.colors['GRAY'] if self.menu_cursor != 1 else self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3 + 20))
        self.game.draw_text(surface, 'Options', self.game.colors['GRAY'] if self.menu_cursor != 2 else self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3 + 40))
        self.game.draw_text(surface, 'Credits', self.game.colors['GRAY'] if self.menu_cursor != 3 else self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3 + 60))
        self.game.draw_text(surface, 'Exit', self.game.colors['GRAY'] if self.menu_cursor != 4 else self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3 + 80))

    def update_cursor(self, keys):
        if keys['ARROW_UP']:
            self.handle_arrow_up_key()
        if keys['ARROW_DOWN']:
            self.handle_arrow_down_key()

    def handle_arrow_up_key(self):
        self.menu_cursor = (self.menu_cursor - 1) % len(self.menu_options)

    def handle_arrow_down_key(self):
        self.menu_cursor = (self.menu_cursor + 1) % len(self.menu_options)