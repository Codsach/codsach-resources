def text_file_operations():
    try:
        # Write to text file
        with open("data.txt", "w") as f:
            f.write("Python File Handling\n")
            f.write("This is a text file.\n")

        # Append to text file
        with open("data.txt", "a") as f:
            f.write("This line is appended.\n")

        # Read text file
        with open("data.txt", "r") as f:
            print("\n--- Text File Content ---")
            print(f.read())

        # Copy text file
        with open("data.txt", "r") as src, open("copy.txt", "w") as dest:
            dest.write(src.read())

        print("Text file copied successfully")

    except Exception as e:
        print("Text File Error:", e)


def binary_file_operations():
    try:
        # Write binary file
        data = b"This is binary file data"
        with open("binaryfile.bin", "wb") as f:
            f.write(data)

        # Read binary file
        with open("binaryfile.bin", "rb") as f:
            print("\n--- Binary File Content ---")
            print(f.read())

        # Copy binary file
        with open("binaryfile.bin", "rb") as src, open("binarycopy.bin", "wb") as dest:
            dest.write(src.read())

        print("Binary file copied successfully")

    except Exception as e:
        print("Binary File Error:", e)


# -------- Main Program --------
print("FILE I/O OPERATIONS DEMONSTRATION")

text_file_operations()
binary_file_operations()

print("\nAll file operations completed successfully")