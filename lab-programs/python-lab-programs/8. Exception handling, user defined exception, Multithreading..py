try:
    a = int(input("Enter a number: "))
    b = int(input("Enter another number: "))
    result = a / b
    print("Result:", result)

except ZeroDivisionError:
    print("Error: Division by zero is not allowed")

except ValueError:
    print("Error: Invalid input")

print("Program completed")
class InvalidMarksError(Exception):
    pass

marks = int(input("Enter marks: "))

try:
    if marks < 0 or marks > 100:
        raise InvalidMarksError("Marks should be between 0 and 100")
    print("Marks accepted")

except InvalidMarksError as e:
    print("User Defined Exception:", e)
    import threading

def divide(a, b):
    try:
        print("Result:", a / b)
    except ZeroDivisionError:
        print("Thread Error: Division by zero")

t1 = threading.Thread(target=divide, args=(10, 2))
t2 = threading.Thread(target=divide, args=(10, 0))

t1.start()
t2.start()

t1.join()
t2.join()

print("Thread execution finished")