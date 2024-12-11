# main.py

from decorators.car_decorator import GPSNavigation
from models.car_inventory import CarInventory
from factories.car_factory import CarFactory
from models.car_builder import CarBuilder


def main():
    # Singleton Pattern - Car Inventory
    car_inventory = CarInventory()
    car_factory = CarFactory()

    # Builder Pattern
    car1 = CarBuilder()
    car1.set_make("Toyota")
    car1.set_model("Camry")
    car1.set_year(2022)
    car1.set_color("Blue")
    car1.add_optional_feature("Autopilot")

    # Factory Pattern
    car2 = car_factory.create("Volvo", "XC90", 2019, "Black")
    car2_gps = GPSNavigation(car2)  # Add GPS Navigation
    car_inventory.add_car(car2_gps)

    # Create a basic car
    basic_car = car1.build()

    # Add features dynamically
    car_with_gps = GPSNavigation(basic_car)  # Add GPS Navigation to basic car
    car_inventory.add_car(car_with_gps)

    # Prototype
    cloned_car = car2.clone()
    car_inventory.add_car(cloned_car)

    # Listing available cars
    print("Available Cars:")
    for car in car_inventory.list_cars():
        features = ", ".join(car.get_optional_features())
        features_str = f" - Optional Features: {features}" if features else ""
        print(f"- {car.description()} - Cost: ${car.cost()}{features_str}")


if __name__ == "__main__":
    main()
