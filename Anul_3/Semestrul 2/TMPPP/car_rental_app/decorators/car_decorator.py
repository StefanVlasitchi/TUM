# decorators/car_decorator.py

from models.car import Car


class CarDecorator(Car):
    def __init__(self, car):
        self.car = car

    def description(self):
        return self.car.description()

    def cost(self):
        return self.car.cost()


# Concrete Decorators
class GPSNavigation(CarDecorator):
    def description(self):
        return self.car.description() + ", GPS Navigation"

    def cost(self):
        return self.car.cost() + 200

    def add_optional_feature(self, feature):
        self.car.add_optional_feature(feature)

    def get_optional_features(self):
        return self.car.get_optional_features()


class HeatedSeats(CarDecorator):
    def description(self):
        return self.car.description() + ", Heated Seats"

    def cost(self):
        return self.car.cost() + 100
