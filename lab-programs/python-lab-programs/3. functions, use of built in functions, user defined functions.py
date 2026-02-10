#user defined functions

def add(a,b):
    return a+b

def subtract(a,b):
    return a-b

def square(n):
    return n*n

def even_or_odd(n):
    if n % 2 == 0:
        return "Even"
    else:
        return "Odd"
    
def factorial(n):
    fact = 1
    for i in range(1,n+1):
        fact *= i
    return fact

numbers = [1,2,3,4,5,6,7,8,9]
def average(numbers):
    return sum(numbers)/len(numbers)

print("\n User Defined Function Outputs")
print("Addition:", add(10,5))
print("Subtraction:", subtract(10,5))
print("Square:", square(6))
print("Even/Odd:", even_or_odd(8))
print("Factorial:", factorial(5))
print("Average:", average(numbers))


#built-in functions

numbers = [10,20,30,40,50]
print("\n Built-in Function Outputs")
print("List:", numbers)
print("Length:", len(numbers))
print("Maximum:", max(numbers))
print("Minimum:", min(numbers))
print("Sum:", sum(numbers))
print("Sorted:", sorted(numbers))
print("Type:", type(numbers))
