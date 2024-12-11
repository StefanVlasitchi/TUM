# app.py
from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.core.window import Window


class LoginRegisterPage(BoxLayout):
    def __init__(self, **kwargs):
        super(LoginRegisterPage, self).__init__(**kwargs)

        # Define layout
        self.orientation = 'vertical'
        self.size_hint = (None, None)
        self.size = (450, 850)
        self.spacing = 10
        self.padding = [20, 250, 20, 250]  # Adjust padding to center content vertically

        # Create text inputs with custom properties
        email_input = TextInput(hint_text='Email/Phone Number', size_hint=(None, None), size=(400, 30),
                                multiline=False,  # Disable multiline
                                font_size=14,  # Font size
                                background_color=(0.95, 0.95, 0.95, 1))  # Light gray background

        password_input = TextInput(hint_text='Password', password=True, size_hint=(None, None), size=(400, 30),
                                   multiline=False,  # Disable multiline
                                   font_size=14,  # Font size
                                   background_color=(0.95, 0.95, 0.95, 1))  # Light gray background

        # Create buttons with custom properties
        forgot_password_button = Button(text='Forgot Password?', size_hint=(None, None), size=(200, 40),
                                        background_normal='', background_color=(0.9, 0.2, 0.3, 1),  # Red background
                                        font_size=14,  # Font size
                                        color=(1, 1, 1, 1))  # Text color

        login_button = Button(text='Login', size_hint=(None, None), size=(200, 40),
                              background_normal='', background_color=(0, 0.6, 0.2, 1),  # Green background
                              font_size=14,  # Font size
                              color=(1, 1, 1, 1))  # Text color

        register_button = Button(text='Register', size_hint=(None, None), size=(200, 40),
                                 background_normal='', background_color=(0.2, 0.4, 0.8, 1),  # Blue background
                                 font_size=14,  # Font size
                                 color=(1, 1, 1, 1))  # Text color

        # Center the widgets
        email_input.pos_hint = {'center_x': 0.5}
        password_input.pos_hint = {'center_x': 0.5}
        forgot_password_button.pos_hint = {'center_x': 0.5}
        login_button.pos_hint = {'center_x': 0.5}
        register_button.pos_hint = {'center_x': 0.5}

        # Add widgets to layout
        self.add_widget(email_input)
        self.add_widget(password_input)
        self.add_widget(forgot_password_button)
        self.add_widget(login_button)
        self.add_widget(register_button)


class CarRentalApp(App):
    def build(self):
        Window.size = (450, 850)  # Set window size
        return LoginRegisterPage()


if __name__ == '__main__':
    CarRentalApp().run()
