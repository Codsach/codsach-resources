FILENAME = "records.txt"

def add_record():
    with open(FILENAME, "a") as file:
        data = input("Enter record to add: ")
        file.write(data + "\n")
    print("Record added successfully")


def search_record():
    keyword = input("Enter text to search: ")
    found = False

    with open(FILENAME, "r") as file:
        for line in file:
            if keyword in line:
                print("Record found:", line.strip())
                found = True

    if not found:
        print("Record not found")


def update_record():
    old_text = input("Enter text to update: ")
    new_text = input("Enter new text: ")

    with open(FILENAME, "r") as file:
        data = file.read()

    if old_text in data:
        data = data.replace(old_text, new_text)

        with open(FILENAME, "w") as file:
            file.write(data)

        print("Record updated successfully")
    else:
        print("Record not found to update")


def display_records():
    print("\n--- File Contents ---")
    with open(FILENAME, "r") as file:
        print(file.read())


# -------- MAIN MENU --------
while True:
    print("\nFILE OPERATIONS MENU")
    print("1. Add Record")
    print("2. Search Record")
    print("3. Update Record")
    print("4. Display All Records")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        add_record()
    elif choice == "2":
        search_record()
    elif choice == "3":
        update_record()
    elif choice == "4":
        display_records()
    elif choice == "5":
        print("Exiting program")
        break
    else:
        print("Invalid choice") 