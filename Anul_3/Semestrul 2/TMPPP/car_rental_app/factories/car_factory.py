# factories/car_factory.py

from models.car import Car
from abc import ABC, abstractmethod

# class CarFactory:
#    @staticmethod
#    def create_car(make, model, year, color):
#        return Car(make, model, year, color)
#
#    @staticmethod
#    def create_suv(make, model, year, color):
#        return Car(f"SUV {make}", model, year, color)
#
#    @staticmethod
#    def create_sports_car(make, model, year, color):
#        return Car(f"Sports {make}", model, year, color)

from models.car import Car
from abc import ABC, abstractmethod

from models.car_builder import CarBuilder


class Factory(ABC):
    @abstractmethod
    def create(self, make, model, year, color):
        pass


class CarFactory(Factory):
    def create(self, make, model, year, color):
        # Use CarBuilder to construct Car objects
        car_builder = CarBuilder()
        car_builder.set_make(make)
        car_builder.set_model(model)
        car_builder.set_year(year)
        car_builder.set_color(color)
        # Add optional features if needed
        car_builder.add_optional_feature("")
        # Build and return the Car object
        return car_builder.build()


class SUVFactory(Factory):
    def create(self, make, model, year, color):
        # Use CarBuilder to construct Car objects
        car_builder = CarBuilder()
        car_builder.set_make(make)
        car_builder.set_model(model)
        car_builder.set_year(year)
        car_builder.set_color(color)
        # Add optional features if needed
        car_builder.add_optional_feature("")
        # Build and return the Car object
        return car_builder.build()


class SportsCarFactory(Factory):
    def create(self, make, model, year, color):
        # Use CarBuilder to construct Car objects
        car_builder = CarBuilder()
        car_builder.set_make(make)
        car_builder.set_model(model)
        car_builder.set_year(year)
        car_builder.set_color(color)
        # Add optional features if needed
        car_builder.add_optional_feature("")
        # Build and return the Car object
        return car_builder.build()
