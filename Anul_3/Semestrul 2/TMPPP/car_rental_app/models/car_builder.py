# models/car_builder.py
from abc import abstractmethod, ABC
from .car import Car


class Builder(ABC):
    @abstractmethod
    def build(self):
        pass


class CarBuilder(Builder):
    def __init__(self):
        self.car = Car()

    def add_optional_feature(self, feature):
        self.car.optional_features.append(feature)
        return self

    def set_make(self, make):
        self.car.make = make
        return self

    def set_model(self, model):
        self.car.model = model
        return self

    def set_year(self, year):
        self.car.year = year
        return self

    def set_color(self, color):
        self.car.color = color
        return self

    def build(self):
        # Ensure that all required attributes are set
        if not all([self.car.make, self.car.model, self.car.year, self.car.color]):
            raise ValueError("Incomplete car information. Make sure all attributes are set.")
        return self.car

