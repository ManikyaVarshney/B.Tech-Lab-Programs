import pygame
import sys

# Initialize pygame
pygame.init()

# Screen dimensions
WIDTH, HEIGHT = 800, 600

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Create the screen
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Bouncing Ball")

# Ball properties
ball_radius = 20
ball_color = BLACK
ball_x = WIDTH // 2
ball_y = HEIGHT // 2
ball_speed_x = 5
ball_speed_y = 5

clock = pygame.time.Clock()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Update ball position
    ball_x += ball_speed_x
    ball_y += ball_speed_y

    # Check for collisions with screen edges
    if ball_x <= 0 or ball_x >= WIDTH:
        ball_speed_x = -ball_speed_x
    if ball_y <= 0 or ball_y >= HEIGHT:
        ball_speed_y = -ball_speed_y

    # Clear the screen
    screen.fill(WHITE)

    # Draw the ball
    pygame.draw.circle(screen, ball_color, (ball_x, ball_y), ball_radius)

    # Update the display
    pygame.display.flip()

    clock.tick(60)  # Limit to 60 frames per second

pygame.quit()
sys.exit()
