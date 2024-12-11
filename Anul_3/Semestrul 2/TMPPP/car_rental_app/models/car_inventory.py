# models/car_inventory.py

class MyCustomError(Exception):
    def __init__(self, message="An error occurred"):
        super().__init__(message)


class CarInventory:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
            cls._instance.cars = []
        else:
            raise MyCustomError("An error occurred ")
        return cls._instance

    def add_car(self, car):
        self.cars.append(car)

    def remove_car(self, car):
        self.cars.remove(car)

    def list_cars(self):
        return self.cars
