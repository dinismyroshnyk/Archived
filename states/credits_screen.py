from states.state import State

class CreditsScreen(State):
    def __init__(self, game):
        State.__init__(self, game)
        self.menu_options = {0: 'Back'}
        self.menu_cursor = 0

    def update(self, dt, keys):
        self.update_cursor(keys)
        if keys['SELECT']:
            selected_option = self.menu_options[self.menu_cursor]
            self.handle_selected_option(selected_option)
        self.game.reset_keys()

    def handle_selected_option(self, option):
        if option == 'Back':
            self.exit_state()

    def render(self, surface):
        surface.fill(self.game.colors['BLACK'])
        self.game.draw_text(surface, 'Credits', self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 4))
        self.game.draw_text(surface, 'Programing: Me', self.game.colors['GRAY'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3))
        self.game.draw_text(surface, 'Art: Stolen', self.game.colors['GRAY'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3 + 20))
        self.game.draw_text(surface, 'Music: NaN', self.game.colors['GRAY'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3 + 40))
        self.game.draw_text(surface, 'Audio: 404' , self.game.colors['GRAY'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3 + 60))
        self.game.draw_text(surface, 'Back', self.game.colors['WHITE'], (self.game.GAME_LOGIC_SIZE[0] / 2, self.game.GAME_LOGIC_SIZE[1] / 3 + 80))

    def update_cursor(self, keys):
        pass