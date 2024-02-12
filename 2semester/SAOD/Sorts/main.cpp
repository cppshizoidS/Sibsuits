#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <mutex>

std::mutex dataMutex;

void drawBars(sf::RenderWindow& window, const std::vector<int>& array, const std::vector<int>& indices);
void drawMenu(sf::RenderWindow& window, const sf::Font& font, const std::string& selectedAlgorithm, bool isRunning);
void drawStats(sf::RenderWindow& window, const sf::Font& font, const sf::String& comparisonsStr, const sf::String& permutationsStr);
void bubbleSort(std::vector<int>& array, sf::RenderWindow& window, int& comparisons, int& permutations, bool& isRunning, bool& stopSortingThread);
void insertionSort(std::vector<int>& array, sf::RenderWindow& window, int& comparisons, int& permutations, bool& isRunning, bool& stopSortingThread);
void selectionSort(std::vector<int>& array, sf::RenderWindow& window, int& comparisons, int& permutations, bool& isRunning, bool& stopSortingThread);
void quickSort(std::vector<int>& array, sf::RenderWindow& window, int& comparisons, int& permutations, int low, int high, bool& isRunning, bool& stopSortingThread);

int main() {
    const int windowWidth = 1000;
    const int windowHeight = 600;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sorting Visualizer");

    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
        return -1;
    }

    sf::Text algorithmText;
    algorithmText.setFont(font);
    algorithmText.setCharacterSize(24);
    algorithmText.setFillColor(sf::Color::White);
    algorithmText.setPosition(windowWidth - 220, 10);

    sf::Text comparisonsText;
    comparisonsText.setFont(font);
    comparisonsText.setCharacterSize(20);
    comparisonsText.setFillColor(sf::Color::White);
    comparisonsText.setPosition(10, 10);

    sf::Text permutationsText;
    permutationsText.setFont(font);
    permutationsText.setCharacterSize(20);
    permutationsText.setFillColor(sf::Color::White);
    permutationsText.setPosition(10, 40);

    std::vector<int> array(windowWidth / 2);
    std::iota(array.begin(), array.end(), 1);
    std::shuffle(array.begin(), array.end(), std::default_random_engine(std::random_device()()));

    bool isRunning = false;
    bool stopSortingThread = false;
    std::thread sortingThread;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (event.mouseButton.x >= windowWidth - 220 && event.mouseButton.x <= windowWidth - 20 &&
                    event.mouseButton.y >= 160 && event.mouseButton.y <= 200) {
                    std::lock_guard<std::mutex> lock(dataMutex);
                    std::shuffle(array.begin(), array.end(), std::default_random_engine(std::random_device()()));
                }
            }
        }

        {
            std::lock_guard<std::mutex> lock(dataMutex);
            window.clear();
            drawBars(window, array, {});
            drawStats(window, font, comparisonsText.getString(), permutationsText.getString());
            drawMenu(window, font, algorithmText.getString(), sortingThread.joinable());
            window.display();
        }

        if (!sortingThread.joinable() && !stopSortingThread) {
            int comparisons = 0;
            int permutations = 0;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                isRunning = true;
                algorithmText.setString("Bubble Sort");
                sortingThread = std::thread(bubbleSort, std::ref(array), std::ref(window), std::ref(comparisons), std::ref(permutations), std::ref(isRunning), std::ref(stopSortingThread));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                isRunning = true;
                algorithmText.setString("Insertion Sort");
                sortingThread = std::thread(insertionSort, std::ref(array), std::ref(window), std::ref(comparisons), std::ref(permutations), std::ref(isRunning), std::ref(stopSortingThread));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                isRunning = true;
                algorithmText.setString("Selection Sort");
                sortingThread = std::thread(selectionSort, std::ref(array), std::ref(window), std::ref(comparisons), std::ref(permutations), std::ref(isRunning), std::ref(stopSortingThread));
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                isRunning = true;
                algorithmText.setString("Quick Sort");
                sortingThread = std::thread(quickSort, std::ref(array), std::ref(window), std::ref(comparisons), std::ref(permutations), 0, array.size() - 1, std::ref(isRunning), std::ref(stopSortingThread));
            }

            {
                std::lock_guard<std::mutex> lock(dataMutex);
                comparisonsText.setString("Comparisons: " + std::to_string(comparisons));
                permutationsText.setString("Permutations: " + std::to_string(permutations));
            }
        }
    }

    stopSortingThread = true;
    if (sortingThread.joinable()) {
        sortingThread.join();
    }

    return 0;
}

void drawBars(sf::RenderWindow& window, const std::vector<int>& array, const std::vector<int>& indices) {
    const float barWidth = static_cast<float>(window.getSize().x) / array.size();
    const float scaleFactor = static_cast<float>(window.getSize().y) / *std::max_element(array.begin(), array.end());

    for (size_t i = 0; i < array.size(); ++i) {
        sf::RectangleShape bar(sf::Vector2f(barWidth, array[i] * scaleFactor));
        bar.setPosition(i * barWidth, window.getSize().y - bar.getSize().y);
        bar.setFillColor((std::find(indices.begin(), indices.end(), i) != indices.end()) ? sf::Color::Red : sf::Color::Green);
        window.draw(bar);
    }
}

void drawStats(sf::RenderWindow& window, const sf::Font& font, const sf::String& comparisonsStr, const sf::String& permutationsStr) {
    sf::Text comparisonsText;
    comparisonsText.setFont(font);
    comparisonsText.setCharacterSize(20);
    comparisonsText.setFillColor(sf::Color::White);
    comparisonsText.setPosition(10, 10);
    comparisonsText.setString(comparisonsStr);

    sf::Text permutationsText;
    permutationsText.setFont(font);
    permutationsText.setCharacterSize(20);
    permutationsText.setFillColor(sf::Color::White);
    permutationsText.setPosition(10, 40);
    permutationsText.setString(permutationsStr);

    window.draw(comparisonsText);
    window.draw(permutationsText);
}

void drawMenu(sf::RenderWindow& window, const sf::Font& font, const std::string& selectedAlgorithm, bool isRunning) {
    sf::RectangleShape menu(sf::Vector2f(220.f, 220.f));
    menu.setFillColor(sf::Color(30, 30, 30));
    menu.setPosition(window.getSize().x - 240.f, 10.f);
    window.draw(menu);

    sf::Text menuText;
    menuText.setFont(font);
    menuText.setCharacterSize(18);
    menuText.setFillColor(sf::Color::White);
    menuText.setPosition(window.getSize().x - 230.f, 20.f);
    menuText.setString("Pick Algorithm:\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Quick Sort");

    sf::Text shuffleButton;
    shuffleButton.setFont(font);
    shuffleButton.setCharacterSize(18);
    shuffleButton.setFillColor(sf::Color::White);
    shuffleButton.setPosition(window.getSize().x - 230.f, 160.f);
    shuffleButton.setString("Shuffle");

    sf::Text selectedAlgorithmText;
    selectedAlgorithmText.setFont(font);
    selectedAlgorithmText.setCharacterSize(18);
    selectedAlgorithmText.setFillColor(sf::Color::White);
    selectedAlgorithmText.setPosition(window.getSize().x - 230.f, 190.f);
    selectedAlgorithmText.setString("Selected Algorithm: " + selectedAlgorithm);

    window.draw(menuText);
    window.draw(shuffleButton);
    window.draw(selectedAlgorithmText);

    if (isRunning) {
        shuffleButton.setString("");
        selectedAlgorithmText.setString("");
    }
}

void bubbleSort(std::vector<int>& array, sf::RenderWindow& window, int& comparisons, int& permutations, bool& isRunning, bool& stopSortingThread) {
    const int size = array.size();

    for (int i = 0; i < size - 1 && !stopSortingThread; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            std::lock_guard<std::mutex> lock(dataMutex);
            comparisons++;
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                permutations++;
            }
        }

        std::lock_guard<std::mutex> lock(dataMutex);
        window.clear();
        drawBars(window, array, {});
        window.display();

        if (isRunning && !stopSortingThread) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

void insertionSort(std::vector<int>& array, sf::RenderWindow& window, int& comparisons, int& permutations, bool& isRunning, bool& stopSortingThread) {
    const int size = array.size();

    for (int i = 1; i < size && !stopSortingThread; ++i) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            std::lock_guard<std::mutex> lock(dataMutex);
            comparisons++;
            array[j + 1] = array[j];
            permutations++;
            j--;
        }

        array[j + 1] = key;

        std::lock_guard<std::mutex> lock(dataMutex);
        window.clear();
        drawBars(window, array, {});
        window.display();

        if (isRunning && !stopSortingThread) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

void selectionSort(std::vector<int>& array, sf::RenderWindow& window, int& comparisons, int& permutations, bool& isRunning, bool& stopSortingThread) {
    const int size = array.size();

    for (int i = 0; i < size - 1 && !stopSortingThread; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < size; ++j) {
            std::lock_guard<std::mutex> lock(dataMutex);
            comparisons++;
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(array[i], array[minIndex]);
        permutations++;

        std::lock_guard<std::mutex> lock(dataMutex);
        window.clear();
        drawBars(window, array, {});
        window.display();

        if (isRunning && !stopSortingThread) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

void quickSort(std::vector<int>& array, sf::RenderWindow& window, int& comparisons, int& permutations, int low, int high, bool& isRunning, bool& stopSortingThread) {
    if (low < high && !stopSortingThread) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; ++j) {
            std::lock_guard<std::mutex> lock(dataMutex);
            comparisons++;
            if (array[j] < pivot) {
                i++;
                std::swap(array[i], array[j]);
                permutations++;
            }
        }

        std::swap(array[i + 1], array[high]);
        permutations++;

        std::lock_guard<std::mutex> lock(dataMutex);
        window.clear();
        drawBars(window, array, {});
        window.display();

        if (isRunning && !stopSortingThread) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }

        int partitionIndex = i + 1;

        quickSort(array, window, comparisons, permutations, low, partitionIndex - 1, isRunning, stopSortingThread);
        quickSort(array, window, comparisons, permutations, partitionIndex + 1, high, isRunning, stopSortingThread);
    }
}
