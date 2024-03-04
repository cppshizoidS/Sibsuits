def selection_sort(word):
    word_list = list(word)
    n = len(word_list)

    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if word_list[j] < word_list[min_index]:
                min_index = j

        word_list[i], word_list[min_index] = word_list[min_index], word_list[i]
        print('Selection Sort:', ''.join(word_list))

    return ''.join(word_list)


def insertion_sort(word):
    word_list = list(word)
    for i in range(1, len(word_list)):
        key = word_list[i]
        j = i - 1

        while j >= 0 and key < word_list[j]:
            word_list[j + 1] = word_list[j]
            j -= 1

        word_list[j + 1] = key
        print('Insertion Sort:', ''.join(word_list))

    return ''.join(word_list)


def bubble_sort(word):
    word_list = list(word)
    n = len(word_list)

    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if word_list[j] > word_list[j + 1]:
                word_list[j], word_list[j + 1] = word_list[j + 1], word_list[j]
        print('Bubble Sort:', ''.join(word_list))

    return ''.join(word_list)


def shaker_sort(word):
    word_list = list(word)
    n = len(word_list)
    swapped = True

    start = 0
    end = n - 1

    while swapped and start < end:
        swapped = False

        for i in range(start, end):
            if word_list[i] > word_list[i + 1]:
                word_list[i], word_list[i + 1] = word_list[i + 1], word_list[i]
                swapped = True

        print('Shaker Sort:', ''.join(word_list))

        if not swapped:
            break

        swapped = False

        end = end - 1

        for i in range(end - 1, start - 1, -1):
            if word_list[i] > word_list[i + 1]:
                word_list[i], word_list[i + 1] = word_list[i + 1], word_list[i]
                swapped = True

        print('Shaker Sort:', ''.join(word_list))

        start = start + 1

    return ''.join(word_list)


def shell_sort(word):
    word_list = list(word)
    n = len(word_list)
    gap = n // 2
    iteration = 0

    while gap > 0:
        for i in range(gap, n):
            temp = word_list[i]
            j = i
            while j >= gap and word_list[j - gap] > temp:
                word_list[j] = word_list[j - gap]
                j -= gap
            word_list[j] = temp

            iteration += 1
            print(f'Shell Sort (Iteration {iteration}, Gap = {
                  gap}):', ''.join(word_list))

        gap //= 2

    return ''.join(word_list)


def main():
    word = input("Enter a word to sort: ")

    # Selection Sort
    sorted_word_selection = selection_sort(word)
    print("Word sorted alphabetically using Selection Sort:", sorted_word_selection)

    # Insertion Sort
    sorted_word_insertion = insertion_sort(word)
    print("Word sorted alphabetically using Insertion Sort:", sorted_word_insertion)

    # Bubble Sort
    sorted_word_bubble = bubble_sort(word)
    print("Word sorted alphabetically using Bubble Sort:", sorted_word_bubble)

    # Shaker Sort
    sorted_word_shaker = shaker_sort(word)
    print("Word sorted alphabetically using Shaker Sort:", sorted_word_shaker)

    # Shell Sort
    sorted_word_shell = shell_sort(word)
    print("Word sorted alphabetically using Shell Sort:", sorted_word_shell)


if __name__ == "__main__":
    main()
