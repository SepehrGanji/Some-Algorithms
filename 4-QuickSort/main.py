from random import randrange

def quicksort(array):
  if(len(array) < 2):
    return array
  
  pivot_index = randrange(len(array))
  pivot = array[pivot_index]
  left = [x for x in array if x < pivot]
  middle = [x for x in array if x == pivot]
  right = [x for x in array if x > pivot]
  return quicksort(left) + middle + quicksort(right)
  

user_input = input("Enter an array of numbers separated by space: ")
array = list(map(int, user_input.split()))
print(quicksort(array))
