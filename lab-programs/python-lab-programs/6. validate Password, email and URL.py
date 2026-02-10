import re

# Password validation
def validate_password(password):
    pattern = r'^(?=.*[A-Z])(?=.*[a-z])(?=.*\d)(?=.*[@#$%^&+=!]).{8,}$'
    if re.match(pattern, password):
        return True
    return False


# Email validation
def validate_email(email):
    pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
    if re.match(pattern, email):
        return True
    return False


# URL validation
def validate_url(url):
    pattern = r'^(https?:\/\/)?([a-zA-Z0-9-]+\.)+[a-zA-Z]{2,}(\/\S*)?$'
    if re.match(pattern, url):
        return True
    return False


# -------- Main Program --------
password = input("Enter Password: ")
email = input("Enter Email: ")
url = input("Enter URL: ")

print("\nValidation Results:")

if validate_password(password):
    print("Password: Valid")
else:
    print("Password: Invalid")

if validate_email(email):
    print("Email: Valid")
else:
    print("Email: Invalid")

if validate_url(url):
    print("URL: Valid")
else:
    print("URL: Invalid")