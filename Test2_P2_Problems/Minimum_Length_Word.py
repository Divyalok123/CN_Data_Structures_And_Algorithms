#Given a string S (that can contain multiple words), you need to find the word which has minimum length.

string = input()

newArr = string.split(" ")

result = newArr[0]

for i in range(1, len(newArr)):
    if(len(newArr[i]) < len(result)):
        result = newArr[i]
        
print(result)
    

