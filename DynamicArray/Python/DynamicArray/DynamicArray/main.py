from DynamicArray import DynamicArray

arr = DynamicArray()
arr.push_back(1)
arr.push_back(2)
arr.push_back(3)
arr.push_back(1)
arr.push_back(5)
arr.insert(2, 4)
print(arr.remove(1))
arr.insert(1, 4)
print(arr)
arr.reverse()
print(arr)