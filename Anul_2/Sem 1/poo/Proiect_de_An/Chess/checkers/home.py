import pygame
from .constants import BACKGROUND
#from .chekers

class Home:
    def __init__(self, win):
        pygame.init()
        self.win = win

    def menu(self):
        """Displays the menu and handles menu events"""
        bg_image = BACKGROUND
        play_button = pygame.Rect(300, 250, 200, 50)
        #settings_button = pygame.Rect(300, 325, 200, 50)
        quit_button = pygame.Rect(300, 400, 200, 50)

        while True:
            self.win.blit(bg_image, (-170, 0))
            pygame.draw.rect(self.win, (255, 255, 255), play_button)
            #pygame.draw.rect(self.win, (255, 255, 255), settings_button)
            pygame.draw.rect(self.win, (255, 255, 255), quit_button)

            font = pygame.font.Font(None, 30)
            play_text = font.render("Play", True, (0, 0, 0))
            #settings_text = font.render("Settings", True, (0, 0, 0))
            quit_text = font.render("Quit", True, (0, 0, 0))
            self.win.blit(play_text, (380, 265))
            #self.win.blit(settings_text, (365, 335))
            self.win.blit(quit_text, (380, 415))
            pygame.display.update()

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    # sys.exit()
                elif event.type == pygame.MOUSEBUTTONDOWN:
                    if play_button.collidepoint(event.pos):
                        return "game"
                    #elif settings_button.collidepoint(event.pos):
                        #return "settings"
                    elif quit_button.collidepoint(event.pos):
                        pygame.quit()
                        # sys.exit()