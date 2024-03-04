def print_sorted_step_with_swaps(word_list, swapped_indices, sort_name):
    sorted_word = ''.join(word_list)
    dots = ['.' if i in swapped_indices else ' ' for i in range(len(sorted_word))]
    print(f'{sort_name}: {sorted_word}')
    print(' ' * (len(sort_name) + 2) + ''.join(dots))


def selection_sort(word):
    word_list = list(word)
    n = len(word_list)

    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if word_list[j] < word_list[min_index]:
                min_index = j

        word_list[i], word_list[min_index] = word_list[min_index], word_list[i]
        print_sorted_step_with_swaps(word_list, [i, min_index], 'Selection Sort')

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
        print_sorted_step_with_swaps(word_list, [i, j + 1], 'Insertion Sort')

    return ''.join(word_list)


def bubble_sort(word):
    word_list = list(word)
    n = len(word_list)

    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if word_list[j] > word_list[j + 1]:
                word_list[j], word_list[j + 1] = word_list[j + 1], word_list[j]
                print_sorted_step_with_swaps(word_list, [j, j + 1], 'Bubble Sort')

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
                print_sorted_step_with_swaps(word_list, [i, i + 1], 'Shaker Sort')

        if not swapped:
            break

        swapped = False

        end = end - 1

        for i in range(end - 1, start - 1, -1):
            if word_list[i] > word_list[i + 1]:
                word_list[i], word_list[i + 1] = word_list[i + 1], word_list[i]
                swapped = True
                print_sorted_step_with_swaps(word_list, [i, i + 1], 'Shaker Sort')

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
            print_sorted_step_with_swaps(word_list, [j], f'Shell Sort (Iteration {iteration}, Gap = {gap})')

        gap //= 2

    return ''.join(word_list)


def main():
    word = input("Enter a word to sort: ")

    # Selection Sort
    sorted_word_selection = selection_sort(word)
    print("\nWord sorted alphabetically using Selection Sort:", sorted_word_selection)

    # Insertion Sort
    sorted_word_insertion = insertion_sort(word)
    print("\nWord sorted alphabetically using Insertion Sort:", sorted_word_insertion)

    # Bubble Sort
    sorted_word_bubble = bubble_sort(word)
    print("\nWord sorted alphabetically using Bubble Sort:", sorted_word_bubble)

    # Shaker Sort
    sorted_word_shaker = shaker_sort(word)
    print("\nWord sorted alphabetically using Shaker Sort:", sorted_word_shaker)

    # Shell Sort
    sorted_word_shell = shell_sort(word)
    print("\nWord sorted alphabetically using Shell Sort:", sorted_word_shell)


if __name__ == "__main__":
    main()
