import random, pygame

class Enemy:
    def __init__(self, game, pos, speed):
        self.game = game
        self.pos = pygame.math.Vector2(pos)
        self.speed = speed
        self.direction = pygame.math.Vector2(random.uniform(-1, 1), random.uniform(-1, 1)).normalize()

    def update(self, dt):
        new_pos = self.pos + self.direction * self.speed * dt
        if 0 <= new_pos.x <= self.game.GAME_LOGIC_SIZE[0] - 128 and 0 <= new_pos.y <= self.game.GAME_LOGIC_SIZE[1] - 128:
            self.pos = new_pos
        if pygame.time.get_ticks() % 60 == 0:
            self.direction = pygame.math.Vector2(random.uniform(-1, 1), random.uniform(-1, 1)).normalize()

    def render(self, surface):
        pygame.draw.circle(surface, (255, 0, 0), (int(self.pos.x), int(self.pos.y)), 10)