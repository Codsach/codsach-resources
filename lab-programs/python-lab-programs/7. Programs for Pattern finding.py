import re

text = "Python is easy. Python version 3"

# match()
if re.match("Python", text):
    print("Match: Pattern found at start")
else:
    print("No match")

# search()
if re.search("easy", text):
    print("Search: Pattern found")
else:
    print("No match")

position = text.find("easy")
print(f"Find: 'easy' starts at index {position}")

# findall()
words = re.findall("Python", text)
print("Findall:", words)

# sub()
new_text = re.sub("Python", "Java", text)
print("Sub:", new_text)

# split()
parts = re.split(" ", text)
print("Split:", parts)

#find()
position = text.find("easy")
print(f"Find: 'easy' starts at index {position}")