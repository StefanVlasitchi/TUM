# models/car.py

import copy


class Car:
    def __init__(self):
        self.make = None
        self.model = None
        self.year = None
        self.color = None
        self.optional_features = []

    def clone(self):
        return copy.deepcopy(self)

    def description(self):
        return f"{self.year} {self.make} {self.model} ({self.color})"

    def cost(self):
        return 0  # Or you can define a default cost here

    def add_optional_feature(self, feature):
        self.optional_features.append(feature)

    def get_optional_features(self):
        return self.optional_features
