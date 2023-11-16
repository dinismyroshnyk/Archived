import pygame

class Menu():
    def __init__(self, game):
        self.game = game
        self.mid_w, self.mid_h = self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2
        self.run_display = True
        self.cursor_rect = pygame.Rect(0, 0, 20, 20)
        self.offset = - 100

    def draw_cursor(self):
        self.game.draw_text('x', 15, (self.cursor_rect.x, self.cursor_rect.y), self.game.WHITE)
        self.game.draw_text('x', 15, (self.cursor_rect.x - (2 * self.offset) + 20, self.cursor_rect.y), self.game.WHITE)

    def blit_screen(self):
        self.game.window.blit(self.game.display, (0, 0))
        pygame.display.update()
        self.game.reset_keys()

    def display_menu(self):
        self.run_display = True
        while self.run_display:
            self.game.check_events()
            self.check_input()
            self.game.display.fill(self.game.BLACK)
            self.draw_menu()
            self.draw_cursor()
            self.blit_screen()

class MainMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.state = "Start"
        self.start_x, self.start_y = self.mid_w, self.mid_h + 30
        self.options_x, self.options_y = self.mid_w, self.mid_h + 50
        self.credits_x, self.credits_y = self.mid_w, self.mid_h + 70
        self.exit_x, self.exit_y = self.mid_w, self.mid_h + 90
        self.cursor_rect.midtop = (self.start_x + self.offset, self.start_y)
        self.state_dict = {
            'Start': {'down': ('Options', self.options_x, self.options_y), 'up': ('Exit', self.exit_x, self.exit_y)},
            'Options': {'down': ('Credits', self.credits_x, self.credits_y), 'up': ('Start', self.start_x, self.start_y)},
            'Credits': {'down': ('Exit', self.exit_x, self.exit_y), 'up': ('Options', self.options_x, self.options_y)},
            'Exit': {'down': ('Start', self.start_x, self.start_y), 'up': ('Credits', self.credits_x, self.credits_y)}
        }

    def draw_menu(self):
        self.game.draw_text('Main Menu', 20, (self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 20), self.game.WHITE)
        self.game.draw_text("Start Game", 15, (self.start_x, self.start_y), self.game.WHITE if self.state == 'Start' else self.game.GRAY)
        self.game.draw_text("Options", 15, (self.options_x, self.options_y), self.game.WHITE if self.state == 'Options' else self.game.GRAY)
        self.game.draw_text("Credits", 15, (self.credits_x, self.credits_y), self.game.WHITE if self.state == 'Credits' else self.game.GRAY)
        self.game.draw_text("Exit", 15, (self.exit_x, self.exit_y), self.game.WHITE if self.state == 'Exit' else self.game.GRAY)

    def move_cursor(self):
        if self.game.DOWN_KEY:
            self.handle_down_key()
        elif self.game.UP_KEY:
            self.handle_up_key()

    def handle_down_key(self):
        self.state, x, y = self.state_dict[self.state]['down']
        self.cursor_rect.midtop = (x + self.offset, y)

    def handle_up_key(self):
        self.state, x, y = self.state_dict[self.state]['up']
        self.cursor_rect.midtop = (x + self.offset, y)

    def check_input(self):
        self.move_cursor()
        if self.game.SELECT_KEY:
            if self.state == 'Start':
                self.game.playing = True
            elif self.state == 'Options':
                self.game.curr_menu = self.game.options
            elif self.state == 'Credits':
                self.game.curr_menu = self.game.credits
            elif self.state == 'Exit':
                self.game.running, self.game.playing = False, False
            self.run_display = False

class OptionsMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.state = 'Volume'
        self.vol_x, self.vol_y = self.mid_w, self.mid_h + 30
        self.controls_x, self.controls_y = self.mid_w, self.mid_h + 50
        self.back_x, self.back_y = self.mid_w, self.mid_h + 70
        self.cursor_rect.midtop = (self.vol_x + self.offset, self.vol_y)
        self.state_dict = {
            'Volume': {'down': ('Controls', self.controls_x, self.controls_y), 'up': ('Back', self.back_x, self.back_y)},
            'Controls': {'down': ('Back', self.back_x, self.back_y), 'up': ('Volume', self.vol_x, self.vol_y)},
            'Back': {'down': ('Volume', self.vol_x, self.vol_y), 'up': ('Controls', self.controls_x, self.controls_y)}
        }

    def draw_menu(self):
        self.game.draw_text('Options', 20, (self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 20), self.game.WHITE)
        self.game.draw_text("Volume", 15, (self.vol_x, self.vol_y), self.game.WHITE if self.state == 'Volume' else self.game.GRAY)
        self.game.draw_text("Controls", 15, (self.controls_x, self.controls_y), self.game.WHITE if self.state == 'Controls' else self.game.GRAY)
        self.game.draw_text("Back", 15, (self.back_x, self.back_y), self.game.WHITE if self.state == 'Back' else self.game.GRAY)

    def move_cursor(self):
        if self.game.DOWN_KEY:
            self.handle_down_key()
        elif self.game.UP_KEY:
            self.handle_up_key()

    def handle_down_key(self):
        self.state, x, y = self.state_dict[self.state]['down']
        self.cursor_rect.midtop = (x + self.offset, y)

    def handle_up_key(self):
        self.state, x, y = self.state_dict[self.state]['up']
        self.cursor_rect.midtop = (x + self.offset, y)

    def check_input(self):
        self.move_cursor()
        if self.game.SELECT_KEY:
            if self.state == 'Volume':
                print('Volume')
            elif self.state == 'Controls':
                print('Controls')
            elif self.state == 'Back':
                self.game.curr_menu = self.game.main_menu
                self.run_display = False

class CreditsMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.state = "Back"
        self.back_x, self.back_y = self.mid_w, self.mid_h + 30
        self.cursor_rect.midtop = (self.back_x + self.offset, self.back_y)

    def draw_menu(self):
        self.game.draw_text('Credits', 20, (self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 20), self.game.WHITE)
        self.game.draw_text('Made by me', 15, (self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 + 10), self.game.GRAY)
        self.game.draw_text("Back", 15, (self.back_x, self.back_y), self.game.WHITE)

    def check_input(self):
        if self.game.SELECT_KEY:
            if self.state == 'Back':
                self.game.curr_menu = self.game.main_menu
                self.run_display = False