// studentapp.cpp
#include "studentapp.hpp"
#include "student.hpp"

#include <QFile>
#include <QFileDialog>
#include <QInputDialog>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QTextStream>
#include <QVBoxLayout>
#include <algorithm>

/**
 * @brief Преобразует объект Student в строковое представление.
 *
 * Эта функция форматирует объект Student как строку, включая имя студента и
 * информацию о каждом предмете и соответствующих оценках.
 *
 * @return QString, представляющий объект Student.
 */
QString Student::toString() const {
  QString result = lastName + ' ' + firstName + ' ' + patronymic + ' ';
  for (const auto &subject : subjects) {
    result += subject.name + ' ' + QString::number(subject.grade) + ' ';
  }
  return result.trimmed();
}

/**
 * @brief Конструирует объект StudentApp.
 *
 * Инициализирует главное окно приложения и настраивает пользовательский
 * интерфейс.
 */
StudentApp::StudentApp(QWidget *parent) : QMainWindow(parent) { setupUi(); }
/**
 * @brief Создает новый текстовый файл.
 *
 *  Данная функция запрашивает у пользователя имя файла с использованием
 * QFileDialog, после чего создает новый текстовый файл с указанным именем.
 * Если пользователь не выбирает имя файла (нажимает "Отмена" в диалоговом
 * окне), функция завершает свою работу без создания файла. Если файл успешно
 * создан, он открывается в режиме QIODevice::WriteOnly и сразу же
 * закрывается.
 *
 * @note Функция использует Qt-классы QFileDialog и QFile.
 *
 * @param[in] this Указатель на текущий объект, который должен быть
 * производным от QObject
 */
void StudentApp::createFile() {
  QString fileName = QFileDialog::getSaveFileName(this, "Create File", "",
                                                  "Text Files (*.txt)");
  if (!fileName.isEmpty()) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
      file.close();
    }
  }
}
/**
 * @brief Добавляет в файл новую запись о студенте.
 *
 * Функция запрашивает у пользователя фамилию, имя, отчество и информацию о
 * предметах студента. Если пользователь отменяет операцию, запись не
 * добавляется.
 *
 * @see addRecordToFile
 */
void StudentApp::addRecord() {
  Student newStudent;
  bool ok;
  newStudent.lastName = QInputDialog::getText(
      this, "Add Record", "Enter Last Name:", QLineEdit::Normal, "", &ok);
  if (!ok)
    return;

  newStudent.firstName = QInputDialog::getText(
      this, "Add Record", "Enter First Name:", QLineEdit::Normal, "", &ok);
  if (!ok)
    return;

  newStudent.patronymic = QInputDialog::getText(
      this, "Add Record", "Enter Patronymic:", QLineEdit::Normal, "", &ok);
  if (!ok)
    return;

  for (int i = 0; i < max_record; ++i) {
    Subject subject;
    subject.name = QInputDialog::getText(this, "Add Record",
                                         "Enter Subject Name " +
                                             QString::number(i + 1) + ":",
                                         QLineEdit::Normal, "", &ok);
    if (!ok)
      return;

    subject.grade = QInputDialog::getInt(
        this, "Add Record", "Enter Grade for " + subject.name + ":", 0, 0, 5, 1,
        &ok);
    if (!ok)
      return;

    newStudent.subjects.push_back(subject);
  }

  addRecordToFile(newStudent);
}
/**
 * @brief Создает индексные файлы для сортировки записей студентов в
 * алфавитном порядке.
 *
 * Функция читает записи из файла, сортирует их по алфавиту и перезаписывает
 * отсортированный результат в тот же файл.
 *
 * @note Функция использует Qt-классы QFile и QTextStream.
 */
void StudentApp::createIndexFiles() {
  QFile inputFile(filename);
  if (inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&inputFile);
    QStringList records;
    while (!in.atEnd()) {
      records << in.readLine();
    }
    inputFile.close();

    std::sort(records.begin(), records.end(),
              [](const QString &a, const QString &b) {
                return a.toLower() < b.toLower();
              });

    QFile sortedFile(filename);
    if (sortedFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QTextStream out(&sortedFile);
      for (const auto &record : records) {
        out << record << '\n';
      }
      sortedFile.close();
      QMessageBox::information(this, "Success",
                               "Index files created successfully.");
    } else {
      QMessageBox::critical(this, "Error", "Unable to create index files.");
    }
  } else {
    QMessageBox::critical(this, "Error", "Unable to open the file.");
  }
}
/**
 * @brief Отображает содержимое файла записей студентов.
 *
 * Функция открывает файл, читает его содержимое и выводит в виджет QTextEdit.
 *
 * @note Функция использует Qt-классы QFile, QTextStream и QTextEdit.
 */
void StudentApp::viewFile() {
  QFile file(filename);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    QString fileContent = in.readAll();
    file.close();

    auto *outputText = findChild<QTextEdit *>();
    if (outputText) {
      outputText->setText(fileContent);
    }
  } else {
    QMessageBox::critical(this, "Error", "Unable to open the file.");
  }
}
/**
 * @brief Ищет и обновляет запись о студенте по фамилии.
 *
 * Функция запрашивает у пользователя фамилию для поиска, затем отображает
 * диалоговое окно для внесения изменений в запись. Если пользователь отменяет
 * операцию, запись не обновляется.
 *
 * @see addRecordToFile
 */
void StudentApp::searchAndUpdateRecord() {
  bool ok;
  QString searchLastName = QInputDialog::getText(this, "Search and Update",
                                                 "Enter Last Name to search:");
  if (searchLastName.isEmpty())
    return;

  auto searchAndUpdateLambda = [this, &ok](const QString &searchLastName) {
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
      QTextStream in(&file);
      QStringList records;
      while (!in.atEnd()) {
        records << in.readLine();
      }
      file.close();

      bool found = false;
      for (auto &record : records) {
        QStringList parts = record.split(' ', Qt::SkipEmptyParts);
        if (!parts.isEmpty() && parts[0] == searchLastName) {
          found = true;

          QInputDialog dialog(this);
          dialog.setWindowTitle("Update Record");
          dialog.setLabelText("Update the record for " + searchLastName);

          if (dialog.exec() == QDialog::Accepted) {
            Student updatedStudent;
            updatedStudent.lastName = parts[0];
            updatedStudent.firstName = parts[1];
            updatedStudent.patronymic = parts[2];

            for (int j = 3; j < parts.size(); j += 2) {
              Subject subject;
              subject.name = parts[j];
              subject.grade = parts[j + 1].toInt();
              updatedStudent.subjects.push_back(subject);
            }

            for (int j = 0; j < updatedStudent.subjects.size(); ++j) {
              Subject &subject = updatedStudent.subjects[j];
              QString updatedName = QInputDialog::getText(
                  this, "Update Subject",
                  "Update Subject Name " + QString::number(j + 1) + ":",
                  QLineEdit::Normal, subject.name, &ok);
              if (!ok)
                return;

              int updatedGrade =
                  QInputDialog::getInt(this, "Update Subject",
                                       "Update Grade for " + updatedName + ":",
                                       subject.grade, 0, 100, 1, &ok);
              if (!ok)
                return;

              subject.name = updatedName;
              subject.grade = updatedGrade;
            }
            record = updatedStudent.toString();
            break;
          }
        }
      }

      if (found) {
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
          QTextStream out(&file);
          for (const auto &updatedRecord : records) {
            out << updatedRecord << '\n';
          }
          file.close();
          QMessageBox::information(this, "Success",
                                   "Record updated successfully.");
        } else {
          QMessageBox::critical(this, "Error", "Unable to update the record.");
        }
      } else {
        QMessageBox::information(this, "Not Found",
                                 "Record not found for " + searchLastName);
      }
    } else {
      QMessageBox::critical(this, "Error", "Unable to open the file.");
    }
  };

  searchAndUpdateLambda(searchLastName);
}

/**
 * @brief Удаляет запись студента по фамилии.
 *
 * Функция запрашивает у пользователя фамилию для поиска и удаляет все записи
 * с указанной фамилией из файла.
 *
 * @note Функция использует Qt-классы QFile, QTextStream и алгоритмы
 * стандартной библиотеки C++.
 */
void StudentApp::deleteRecord() {
  QString deleteLastName = QInputDialog::getText(this, "Delete Record",
                                                 "Enter Last Name to delete:");
  if (deleteLastName.isEmpty())
    return;

  QFile file(filename);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    QStringList records;
    while (!in.atEnd()) {
      records << in.readLine();
    }
    file.close();

    int initialCount = records.size();
    auto removeCondition = [deleteLastName](const QString &record) {
      QStringList parts = record.split(' ', Qt::SkipEmptyParts);
      return !parts.isEmpty() &&
             parts[0].compare(deleteLastName, Qt::CaseInsensitive) == 0;
    };

    records.erase(
        std::remove_if(records.begin(), records.end(), removeCondition),
        records.end());

    if (initialCount > records.size()) {
      QFile updatedFile(filename);
      if (updatedFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&updatedFile);
        for (const auto &updatedRecord : records) {
          out << updatedRecord << '\n';
        }
        updatedFile.close();
        QMessageBox::information(this, "Success",
                                 "Record deleted successfully.");
      } else {
        QMessageBox::critical(this, "Error", "Unable to delete the record.");
      }
    } else {
      QMessageBox::information(this, "Not Found",
                               "Record not found for " + deleteLastName);
    }
  } else {
    QMessageBox::critical(this, "Error", "Unable to open the file.");
  }
}
/**
 * @brief Добавляет запись о студенте в файл.
 *
 * Эта функция добавляет запись о студенте в файл, включая фамилию, имя,
 * отчество и информацию о каждом предмете и соответствующих оценках.
 *
 * @param student Объект Student, который должен быть добавлен в файл.
 */
void StudentApp::addRecordToFile(const Student &student) {
  QFile file(filename);
  if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
    QTextStream stream(&file);
    stream << student.lastName << ' ' << student.firstName << ' '
           << student.patronymic << ' ';
    for (const auto &subject : student.subjects) {
      stream << subject.name << ' ' << subject.grade << ' ';
    }
    stream << '\n';
    file.close();
  }
}
/**
 * @brief Настраивает пользовательский интерфейс приложения.
 *
 * Эта функция создает главное окно, настраивает компоновку и добавляет
 * различные кнопки и виджеты для взаимодействия с пользователем.
 */
void StudentApp::setupUi() {
  auto *centralWidget = new QWidget(this);
  setCentralWidget(centralWidget);

  auto *layout = new QVBoxLayout(centralWidget);

  auto *titleLabel = new QLabel("Student Records Management", this);
  titleLabel->setAlignment(Qt::AlignCenter);
  layout->addWidget(titleLabel);

  auto *createFileButton = new QPushButton("Create File", this);
  connect(createFileButton, &QPushButton::clicked, this,
          &StudentApp::createFile);
  layout->addWidget(createFileButton);

  auto *addRecordButton = new QPushButton("Add Record", this);
  connect(addRecordButton, &QPushButton::clicked, this, &StudentApp::addRecord);
  layout->addWidget(addRecordButton);

  auto *createIndexFilesButton = new QPushButton("Create Index Files", this);
  connect(createIndexFilesButton, &QPushButton::clicked, this,
          &StudentApp::createIndexFiles);
  layout->addWidget(createIndexFilesButton);

  auto *viewFileButton = new QPushButton("View File", this);
  connect(viewFileButton, &QPushButton::clicked, this, &StudentApp::viewFile);
  layout->addWidget(viewFileButton);

  auto *searchAndUpdateButton =
      new QPushButton("Search and Update Record", this);
  connect(searchAndUpdateButton, &QPushButton::clicked, this,
          &StudentApp::searchAndUpdateRecord);
  layout->addWidget(searchAndUpdateButton);

  auto *deleteRecordButton = new QPushButton("Delete Record", this);
  connect(deleteRecordButton, &QPushButton::clicked, this,
          &StudentApp::deleteRecord);
  layout->addWidget(deleteRecordButton);

  auto *outputText = new QTextEdit(this);
  layout->addWidget(outputText);
}
