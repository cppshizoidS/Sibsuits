#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Сравнивает две строки без учета регистра символов.
 * @param a Первая строка для сравнения.
 * @param b Вторая строка для сравнения.
 * @return true, если первая строка меньше второй без учета регистра, иначе false.
 */
bool caseInsensitiveCompare(const std::string &a, const std::string &b) {
  return std::lexicographical_compare(
      a.begin(), a.end(), b.begin(), b.end(),
      [](char a, char b) { return tolower(a) < tolower(b); });
}

/**
 * @brief Основная функция программы.
 * 
 * Читает строки из файла, разбивает их на слова, сортирует слова и записывает
 * отсортированный список в другой файл.
 * 
 * @return 0 в случае успешного выполнения, 1 в случае ошибки.
 */
int main() {
  // Чтение строк из файла
  std::ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
    std::cerr << "Unable to open input file." << std::endl;
    return 1;
  }

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(inputFile, line)) {
    lines.push_back(line);
  }
  inputFile.close();

  // Разбиение строк на слова
  std::vector<std::string> words;
  for (const auto &line : lines) {
    size_t start = 0;
    size_t end = line.find(' ');

    while (end != std::string::npos) {
      std::string word = line.substr(start, end - start);
      if (!word.empty()) { //  условие, чтобы исключить пустые слова
        words.push_back(word);
      }
      start = end + 1;
      end = line.find(' ', start);
    }

    std::string lastWord = line.substr(start);
    if (!lastWord.empty()) {
      words.push_back(lastWord);
    }
  }

  // Сортировка слов
  std::sort(words.begin(), words.end(), caseInsensitiveCompare);

  // Вывод отсортированных слов во второй файл
  std::ofstream outputFile("output.txt");
  if (!outputFile.is_open()) {
    std::cerr << "Unable to open output file." << std::endl;
    return 1;
  }

  for (const auto &word : words) {
    outputFile << word << ' ';
  }

  outputFile.close();

  std::cout << "Words sorted and written to output.txt." << std::endl;

  return 0;
}
