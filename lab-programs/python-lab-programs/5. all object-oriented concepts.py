from abc import ABC, abstractmethod

# Abstraction + Encapsulation
class Vehicle(ABC):
    def __init__(self, name):
        self.__name = name   # Encapsulation (private variable)

    def get_name(self):
        return self.__name   # Encapsulation (getter method)

    @abstractmethod
    def move(self):
        pass                # Abstraction

# Inheritance
class Car(Vehicle):
    def __init__(self, name, fuel_type):
        super().__init__(name)
        self.fuel_type = fuel_type

    # Polymorphism (method overriding)
    def move(self):
        print(self.get_name(), "moves on four wheels using", self.fuel_type)

class Bike(Vehicle):
    def move(self):
        print(self.get_name(), "moves on two wheels")

# Main function
def main():
    v1 = Car("Tesla", "Electric")
    v2 = Bike("Yamaha")

    vehicles = [v1, v2]

    # Polymorphism
    for v in vehicles:
        v.move()

# Calling main
main()
