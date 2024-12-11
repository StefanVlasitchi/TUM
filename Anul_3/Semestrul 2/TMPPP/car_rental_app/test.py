from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.boxlayout import BoxLayout
from main import main  # Import the main function from main.py

class CarRentalApp(App):
    def build(self):
        # Call the main function to retrieve car inventory and rental objects
        car_inventory, rental1, rental2 = main()

        # Create a box layout to organize widgets vertically
        layout = BoxLayout(orientation='vertical')

        # Display car inventory information
        inventory_label = Label(text="Available Cars:", font_size=20)
        layout.add_widget(inventory_label)
        for car in car_inventory.list_cars():
            car_label = Label(text=f"- {car.year} {car.make} {car.model} ({car.color})")
            layout.add_widget(car_label)

        # Display rental information
        rental_label = Label(text="\nRentals:", font_size=20)
        layout.add_widget(rental_label)
        rental1_label = Label(text=f"Customer: {rental1.customer_name}, Duration: {rental1.rental_duration} days, Cost: ${rental1.total_cost}")
        rental2_label = Label(text=f"Customer: {rental2.customer_name}, Duration: {rental2.rental_duration} days, Cost: ${rental2.total_cost}")
        layout.add_widget(rental1_label)
        layout.add_widget(rental2_label)

        return layout

if __name__ == "__main__":
    CarRentalApp().run()
