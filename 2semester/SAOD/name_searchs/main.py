def binary_search(arr, target):
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        mid_char = arr[mid]

        print(f"Checking character at index {mid}: {mid_char}")

        if mid_char == target:
            return mid  # Target found, return the index
        elif mid_char < target:
            low = mid + 1  # Search in the right half
        else:
            high = mid - 1  # Search in the left half

    return -1  # Target not found

# Take user input for unsorted characters
input_chars = input("Enter characters (without spaces): ")

# Convert input to a list of characters and sort it
sorted_chars = sorted(list(input_chars))

# Take user input for the target character
target_char = input("Enter the character to search for: ")

# Perform binary search
result = binary_search(sorted_chars, target_char)

# Display the result
if result != -1:
    print(f"The character '{target_char}' is found at index {result}.")
else:
    print(f"The character '{target_char}' is not in the list.")
