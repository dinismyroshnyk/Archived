import pygame

class Menu():
    def __init__(self, game):
        self.game = game
        self.mid_w, self.mid_h = self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2
        self.run_display = True
        self.offset = - 100

    def update_positions(self):
        pass

    def blit_screen(self):
        self.game.window.blit(self.game.display, (0, 0))
        pygame.display.update()
        self.game.reset_keys()

    def display_menu(self):
        self.run_display = True
        while self.run_display:
            self.game.check_events()
            self.update_positions()
            self.check_input()
            self.game.display.fill(self.game.BLACK)
            self.draw_menu()
            self.blit_screen()

class MainMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.state = "Start"
        self.update_positions()
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

    def handle_up_key(self):
        self.state, x, y = self.state_dict[self.state]['up']

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

    def update_positions(self):
        self.mid_w, self.mid_h = self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2
        self.start_x, self.start_y = self.mid_w, self.mid_h + 30
        self.options_x, self.options_y = self.mid_w, self.mid_h + 50
        self.credits_x, self.credits_y = self.mid_w, self.mid_h + 70
        self.exit_x, self.exit_y = self.mid_w, self.mid_h + 90

class OptionsMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.state = 'Resolution'
        self.update_positions()
        self.state_dict = {
            'Resolution': {'down': ('Controls', self.controls_x, self.controls_y), 'up': ('Back', self.back_x, self.back_y)},
            'Controls': {'down': ('Back', self.back_x, self.back_y), 'up': ('Resolution', self.res_x, self.res_y)},
            'Back': {'down': ('Resolution', self.res_x, self.res_y), 'up': ('Controls', self.controls_x, self.controls_y)}
        }

    def draw_menu(self):
        self.game.draw_text('Options', 20, (self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 20), self.game.WHITE)
        self.game.draw_text("Resolution", 15, (self.res_x, self.res_y), self.game.WHITE if self.state == 'Resolution' else self.game.GRAY)
        self.game.draw_text("Controls", 15, (self.controls_x, self.controls_y), self.game.WHITE if self.state == 'Controls' else self.game.GRAY)
        self.game.draw_text("Back", 15, (self.back_x, self.back_y), self.game.WHITE if self.state == 'Back' else self.game.GRAY)

    def move_cursor(self):
        if self.game.DOWN_KEY:
            self.handle_down_key()
        elif self.game.UP_KEY:
            self.handle_up_key()

    def handle_down_key(self):
        self.state, x, y = self.state_dict[self.state]['down']

    def handle_up_key(self):
        self.state, x, y = self.state_dict[self.state]['up']

    def check_input(self):
        self.move_cursor()
        if self.game.SELECT_KEY:
            if self.state == 'Resolution':
                self.game.curr_menu = self.game.resolution
            elif self.state == 'Controls':
                print('Controls')
            elif self.state == 'Back':
                self.game.curr_menu = self.game.main_menu
            self.run_display = False

    def update_positions(self):
        self.mid_w, self.mid_h = self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2
        self.res_x, self.res_y = self.mid_w, self.mid_h + 30
        self.controls_x, self.controls_y = self.mid_w, self.mid_h + 50
        self.back_x, self.back_y = self.mid_w, self.mid_h + 70

class CreditsMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.state = "Back"
        self.update_positions()

    def draw_menu(self):
        self.game.draw_text('Credits', 20, (self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 20), self.game.WHITE)
        self.game.draw_text('Made by me', 15, (self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 + 10), self.game.GRAY)
        self.game.draw_text('Back', 15, (self.back_x, self.back_y), self.game.WHITE)

    def check_input(self):
        if self.game.SELECT_KEY:
            if self.state == 'Back':
                self.game.curr_menu = self.game.main_menu
                self.run_display = False

    def update_positions(self):
        self.mid_w, self.mid_h = self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2
        self.back_x, self.back_y = self.mid_w, self.mid_h + 30

class ResolutionMenu(Menu):
    def __init__(self, game):
        Menu.__init__(self, game)
        self.state = "Fullscreen"
        self.update_positions()
        self.state_dict = {
            'Fullscreen': {'down': ('1920x1080', self.d_1920x1080_x, self.d_1920x1080_y), 'up': ('Back', self.back_x, self.back_y)},
            '1920x1080': {'down': ('1280x720', self.d_1280x720_x, self.d_1280x720_y), 'up': ('Fullscreen', self.fullscreen_x, self.fullscreen_y)},
            '1280x720': {'down': ('1024x768', self.d_1024x768_x, self.d_1024x768_y), 'up': ('1920x1080', self.d_1920x1080_x, self.d_1920x1080_y)},
            '1024x768': {'down': ('800x600', self.d_800x600_x, self.d_800x600_y), 'up': ('1280x720', self.d_1280x720_x, self.d_1280x720_y)},
            '800x600': {'down': ('Back', self.back_x, self.back_y), 'up': ('1024x768', self.d_1024x768_x, self.d_1024x768_y)},
            'Back': {'down': ('Fullscreen', self.fullscreen_x, self.fullscreen_y), 'up': ('800x600', self.d_800x600_x, self.d_800x600_y)}
        }

    def draw_menu(self):
        self.game.draw_text('Resolution', 20, (self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2 - 20), self.game.WHITE)
        self.game.draw_text('Fullscreen', 15, (self.fullscreen_x, self.fullscreen_y), self.game.WHITE if self.state == 'Fullscreen' else self.game.GRAY)
        self.game.draw_text("1920x1080", 15, (self.d_1920x1080_x, self.d_1920x1080_y), self.game.WHITE if self.state == '1920x1080' else self.game.GRAY)
        self.game.draw_text("1280x720", 15, (self.d_1280x720_x, self.d_1280x720_y), self.game.WHITE if self.state == '1280x720' else self.game.GRAY)
        self.game.draw_text("1024x768", 15, (self.d_1024x768_x, self.d_1024x768_y), self.game.WHITE if self.state == '1024x768' else self.game.GRAY)
        self.game.draw_text("800x600", 15, (self.d_800x600_x, self.d_800x600_y), self.game.WHITE if self.state == '800x600' else self.game.GRAY)
        self.game.draw_text("Back", 15, (self.back_x, self.back_y), self.game.WHITE if self.state == 'Back' else self.game.GRAY)

    def move_cursor(self):
        if self.game.DOWN_KEY:
            self.handle_down_key()
        elif self.game.UP_KEY:
            self.handle_up_key()

    def handle_down_key(self):
        self.state, x, y = self.state_dict[self.state]['down']

    def handle_up_key(self):
        self.state, x, y = self.state_dict[self.state]['up']

    def check_input(self):
        self.move_cursor()
        if self.game.SELECT_KEY:
            if self.state == 'Fullscreen':
                self.game.window = pygame.display.set_mode((self.game.DISPLAY_W,self.game.DISPLAY_H), pygame.FULLSCREEN)
                self.game.DISPLAY_W, self.game.DISPLAY_H = pygame.display.Info().current_w, pygame.display.Info().current_h
            elif self.state == '1920x1080':
                self.game.window = pygame.display.set_mode(self.game.d_1920x1080)
                self.game.DISPLAY_W, self.game.DISPLAY_H = self.game.d_1920x1080
            elif self.state == '1280x720':
                self.game.window = pygame.display.set_mode(self.game.d_1280x720)
                self.game.DISPLAY_W, self.game.DISPLAY_H = self.game.d_1280x720
            elif self.state == '1024x768':
                self.game.window = pygame.display.set_mode(self.game.d_1024x768)
                self.game.DISPLAY_W, self.game.DISPLAY_H = self.game.d_1024x768
            elif self.state == '800x600':
                self.game.window = pygame.display.set_mode(self.game.d_800x600)
                self.game.DISPLAY_W, self.game.DISPLAY_H = self.game.d_800x600
            elif self.state == 'Back':
                self.game.curr_menu = self.game.options
                self.run_display = False

    def update_positions(self):
        self.mid_w, self.mid_h = self.game.DISPLAY_W / 2, self.game.DISPLAY_H / 2
        self.fullscreen_x, self.fullscreen_y = self.mid_w, self.mid_h + 30
        self.d_1920x1080_x, self.d_1920x1080_y = self.mid_w, self.mid_h + 50
        self.d_1280x720_x, self.d_1280x720_y = self.mid_w, self.mid_h + 70
        self.d_1024x768_x, self.d_1024x768_y = self.mid_w, self.mid_h + 90
        self.d_800x600_x, self.d_800x600_y = self.mid_w, self.mid_h + 110
        self.back_x, self.back_y = self.mid_w, self.mid_h + 130