from states.state import State

class PauseScreen(State):
    def __init__(self, game):
        State.__init__(self, game)
        self.menu_options = {0: 'Resume', 1: 'Main Menu', 2: 'Quit'}
        self.menu_cursor = 0

    def update(self, dt, keys):
        self.update_cursor(keys)
        if keys['SELECT']:
            selected_option = self.menu_options[self.menu_cursor]
            self.handle_selected_option(selected_option)
        self.game.reset_keys()

    def handle_selected_option(self, option):
        if option == 'Resume':
            self.exit_state()
        if option == 'Main Menu':
            self.exit_state()
            self.exit_state()
            self.game.player.client.disconnect()
        if option == 'Quit':
            self.game.running, self.game.playing = False, False
            self.game.player.client.disconnect()

    def render(self, surface):
        surface.fill(self.game.colors['BLACK'])
        self.game.draw_text(surface, 'Paused', self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 4))
        self.game.draw_text(surface, 'Resume', self.game.colors['GRAY'] if self.menu_cursor != 0 else self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3))
        self.game.draw_text(surface, 'Main menu', self.game.colors['GRAY'] if self.menu_cursor != 1 else self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3 + 20))
        self.game.draw_text(surface, 'Quit', self.game.colors['GRAY'] if self.menu_cursor != 2 else self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3 + 40))

    def update_cursor(self, keys):
        if keys['ARROW_UP']:
            self.handle_arrow_up_key()
        if keys['ARROW_DOWN']:
            self.handle_arrow_down_key()

    def handle_arrow_up_key(self):
        self.menu_cursor = (self.menu_cursor - 1) % len(self.menu_options)

    def handle_arrow_down_key(self):
        self.menu_cursor = (self.menu_cursor + 1) % len(self.menu_options)