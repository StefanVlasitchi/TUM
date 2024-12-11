# factories/rental_factory.py

from models.rental import Rental

class RentalFactory:
    @staticmethod
    def create_rental(customer_name, rental_duration, total_cost):
        return Rental(customer_name, rental_duration, total_cost)

    @staticmethod
    def create_long_term_rental(customer_name, rental_duration, total_cost):
        total_cost *= 0.9  # Apply 10% discount for long-term rentals
        return Rental(customer_name, rental_duration, total_cost)
