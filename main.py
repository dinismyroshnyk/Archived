import pygame
from pygame.locals import *

# Pygame initialization
pygame.init()

# Variables
running = True
fps = 60
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
size = (1280, 720)

# Create a BLACK screen with a size of 1280x720
screen = pygame.display.set_mode(size)
screen.fill(BLACK)

# Set the title of the window
pygame.display.set_caption("Testing")

# Player class
class Player(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.Surface((25, 25))
        self.image.fill(WHITE)
        self.rect = self.image.get_rect()
        self.rect.center = (size[0] / 2, size[1] / 2)
        self.pos = pygame.math.Vector2(self.rect.center)
        self.speed = 5
    def move(self):
        keys = pygame.key.get_pressed()
        direction = pygame.math.Vector2(0, 0)
        if keys[K_w] or keys[K_UP]:
            direction.y -= 1
        if keys[K_s] or keys[K_DOWN]:
            direction.y += 1
        if keys[K_a] or keys[K_LEFT]:
            direction.x -= 1
        if keys[K_d] or keys[K_RIGHT]:
            direction.x += 1
        # Normalize the direction vector
        if direction.length() > 0:
            direction = direction.normalize() * self.speed
            self.pos += direction
        # Boundaries
        self.rect.center = self.pos
        self.rect.clamp_ip(screen.get_rect())
    def draw(self, screen):
        screen.blit(self.image, self.rect)

# Create a player object
player = Player()

# Main loop
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    # Clear screen
    screen.fill(BLACK)
    # Update
    player.move()
    # Draw
    player.draw(screen)
    pygame.display.update()
    # Set FPS
    pygame.time.Clock().tick(fps)

pygame.quit()