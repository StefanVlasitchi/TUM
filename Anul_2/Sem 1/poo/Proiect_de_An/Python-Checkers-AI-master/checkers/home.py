import pygame
#from .chekers

class Home:
    # Initialize pygame
    pygame.init()

    
    # Load background image
BG_IMAGE = pygame.image.load("chess_bg.jpg")
pygame.display.set_caption("Chess Game")

    # Set screen size and caption
SCREEN = pygame.display.set_mode((800, 600))
    
def init(self):
        # Main menu loop
        while True:
            # Blit background image to screen
            SCREEN.blit(BG_IMAGE, (0, 0))

            # Draw buttons (play, settings, quit)
            play_button = pygame.Rect(300, 250, 200, 50)
            settings_button = pygame.Rect(300, 325, 200, 50)
            quit_button = pygame.Rect(300, 400, 200, 50)
            pygame.draw.rect(SCREEN, (255, 255, 255), play_button)
            pygame.draw.rect(SCREEN, (255, 255, 255), settings_button)
            pygame.draw.rect(SCREEN, (255, 255, 255), quit_button)

            # Add text to buttons
            font = pygame.font.Font(None, 30)
            play_text = font.render("Play", True, (0, 0, 0))
            settings_text = font.render("Settings", True, (0, 0, 0))
            quit_text = font.render("Quit", True, (0, 0, 0))
            SCREEN.blit(play_text, (385, 260))
            SCREEN.blit(settings_text, (365, 335))
            SCREEN.blit(quit_text, (400, 405))

            # Update display
            pygame.display.update()

            # Handle events
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    
                elif event.type == pygame.MOUSEBUTTONDOWN:
                    # Check if buttons were clicked
                    if play_button.collidepoint(event.pos):
                        # Start game
                        pass
                    elif settings_button.collidepoint(event.pos):
                        # Open settings menu
                        pass
                    elif quit_button.collidepoint(event.pos):
                        pygame.quit()
                        