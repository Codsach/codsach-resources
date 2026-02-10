#integer
a = 10
print(type(a))

#float
b = 22.89
print(type(b))

#complex
c = 4 + 3j
print(type(c))

#string
x = "sachin"
print(type(a))

#boolean
y = True
print(type(y))

#list
z = [1,2,3,4,5]
print(type(a))

#set
m = {5,6,7,8}
print(type(m))

#tuple
n = (9,10,11,12)
print(type(n))

#dist
o = {1:"strike", 2:"mca", 3:[1,2,3,4]}
print(type(o))

#control flow statements(if,elif,else)
num = 5
if num > 0:
    print("Postive Number")
elif num == 0:
    print("Zero")
else:
    print("Negative Number")


#blocks in python(Indentation Matters)
x = 20
if x > 10:
    print("Inside block")
    print("Still inside block")
print("Outside block")


#loops
#for loop
for i in range(1,6):
    print("Numbers:",i)

#while loop
count = 1
while count <= 5:
    print("count:",count)
    count += 1

#break statement
for i in range(10):
    if i == 5:
        break
    print(i)

#continue statement
for i in range(6):
    if i == 3:
        continue
    print(i)