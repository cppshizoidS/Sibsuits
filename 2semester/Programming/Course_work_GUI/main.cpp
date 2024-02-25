#include <QApplication>
#include <QFileDialog>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <algorithm>
/**
 * @brief Структура для представления информации о предмете.
 */
struct Subject {
  QString name;  ///< Название предмета.
  int grade;
};
/**
 * @brief Структура для представления информации о студенте.
 */
struct Student {
  QString lastName;           ///< Фамилия студента.
  QString firstName;          ///< Имя студента.
  QString patronymic;         ///< Отчество студента.
  QVector<Subject> subjects;  ///< Вектор с информацией о предметах студента.
};
/**
 * @brief StudentApp класс для управления записями учащихся
 */
class StudentApp : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief Конструктор класса StudentApp.
   * @param parent Родительский виджет.
   */
  explicit StudentApp(QWidget *parent = nullptr) : QMainWindow(parent) {
    setupUi();
  }

 private slots:
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
  void createFile() {
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
  void addRecord() {
    Student newStudent;
    bool ok;
    newStudent.lastName = QInputDialog::getText(
        this, "Add Record", "Enter Last Name:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    newStudent.firstName = QInputDialog::getText(
        this, "Add Record", "Enter First Name:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    newStudent.patronymic = QInputDialog::getText(
        this, "Add Record", "Enter Patronymic:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    for (int i = 0; i < max_record; ++i) {
      Subject subject;
      subject.name = QInputDialog::getText(
          this, "Add Record",
          "Enter Subject Name " + QString::number(i + 1) + ":",
          QLineEdit::Normal, "", &ok);
      if (!ok) return;

      subject.grade = QInputDialog::getInt(
          this, "Add Record", "Enter Grade for " + subject.name + ":", 0, 0,
          100, 1, &ok);
      if (!ok) return;

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
  void createIndexFiles() {
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
  void viewFile() {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QTextStream in(&file);
      QString fileContent = in.readAll();
      file.close();

      /// Отображение содержимого файла в виджете QTextEdit
      QTextEdit *outputText = findChild<QTextEdit *>();
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
  void searchAndUpdateRecord() {
    QString searchLastName = QInputDialog::getText(
        this, "Search and Update", "Enter Last Name to search:");
    if (searchLastName.isEmpty()) return;

    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QTextStream in(&file);
      QStringList records;
      while (!in.atEnd()) {
        records << in.readLine();
      }
      file.close();

      bool found = false;
      for (QString &record : records) {
        QStringList parts = record.split(' ', Qt::SkipEmptyParts);
        if (!parts.isEmpty() && parts[0] == searchLastName) {
          found = true;

          QInputDialog dialog(this);
          dialog.setWindowTitle("Update Record");
          dialog.setLabelText("Update the record for " + searchLastName);

          if (dialog.exec() == QDialog::Accepted) {
            QFile updatedFile(filename);
            if (updatedFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
              QTextStream out(&updatedFile);
              for (const auto &updatedRecord : records) {
                out << updatedRecord << '\n';
              }
              updatedFile.close();
              QMessageBox::information(this, "Success",
                                       "Record updated successfully.");
            } else {
              QMessageBox::critical(this, "Error",
                                    "Unable to update the record.");
            }
          }

          break;
        }
      }

      if (!found) {
        QMessageBox::information(this, "Not Found",
                                 "Record not found for " + searchLastName);
      }
    } else {
      QMessageBox::critical(this, "Error", "Unable to open the file.");
    }
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
  void deleteRecord() {
    QString deleteLastName = QInputDialog::getText(
        this, "Delete Record", "Enter Last Name to delete:");
    if (deleteLastName.isEmpty()) return;

    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QTextStream in(&file);
      QStringList records;
      while (!in.atEnd()) {
        records << in.readLine();
      }
      file.close();

      /// Удаление всех записей с заданной фамилией
      int initialCount = records.size();
      auto removeCondition = [deleteLastName](const QString &record) {
        QStringList parts = record.split(' ', Qt::SkipEmptyParts);
        return !parts.isEmpty() &&
               parts[0].compare(deleteLastName, Qt::CaseInsensitive) == 0;
      };

      records.erase(
          std::remove_if(records.begin(), records.end(), removeCondition),
          records.end());

      /// Если какие-либо записи были удалены, обновляем файл.
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
   * @brief Максимальное количество предметов в записи учащегося
   */
 private:
  /**
   * @brief Максимальное количество предметов в записи студента.
   */
  const int max_record = 4;
  /**
   * @brief Имя файла по умолчанию для хранения записей учащихся.
   */
  QString filename = "students.txt";

  /**
   * @brief Инициализирует пользовательский интерфейс приложения.
   *
   * Создает виджет, который становится центральным виджетом главного окна.
   * Затем создает вертикальный лэйаут и добавляет его в центральный виджет.
   * Добавляет заголовок, кнопки и виджет QTextEdit для отображения содержимого
   * файла записей студентов.
   *
   * @note Функция использует Qt-классы QWidget, QVBoxLayout, QLabel,
   * QPushButton и QTextEdit.
   */
  void setupUi() {
    // Создание центрального виджета
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Создание вертикального лэйаута для центрального виджета
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Добавление заголовка
    QLabel *titleLabel = new QLabel("Student Records Management", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);

    // Добавление кнопок для управления записями студентов
    QPushButton *createFileButton = new QPushButton("Create File", this);
    connect(createFileButton, &QPushButton::clicked, this,
            &StudentApp::createFile);
    layout->addWidget(createFileButton);

    QPushButton *addRecordButton = new QPushButton("Add Record", this);
    connect(addRecordButton, &QPushButton::clicked, this,
            &StudentApp::addRecord);
    layout->addWidget(addRecordButton);

    QPushButton *createIndexFilesButton =
        new QPushButton("Create Index Files", this);
    connect(createIndexFilesButton, &QPushButton::clicked, this,
            &StudentApp::createIndexFiles);
    layout->addWidget(createIndexFilesButton);

    QPushButton *viewFileButton = new QPushButton("View File", this);
    connect(viewFileButton, &QPushButton::clicked, this, &StudentApp::viewFile);
    layout->addWidget(viewFileButton);

    QPushButton *searchAndUpdateButton =
        new QPushButton("Search and Update Record", this);
    connect(searchAndUpdateButton, &QPushButton::clicked, this,
            &StudentApp::searchAndUpdateRecord);
    layout->addWidget(searchAndUpdateButton);

    QPushButton *deleteRecordButton = new QPushButton("Delete Record", this);
    connect(deleteRecordButton, &QPushButton::clicked, this,
            &StudentApp::deleteRecord);
    layout->addWidget(deleteRecordButton);

    // Добавление виджета QTextEdit для отображения содержимого файла
    QTextEdit *outputText = new QTextEdit(this);
    layout->addWidget(outputText);
  }

  /**
   * @brief Добавляет запись о студенте в файл.
   * @param student Объект student, содержащий запись.
   *
   * Функция добавляет информацию о студенте, включая фамилию, имя, отчество и
   * информацию о предметах, в конец файла. Если файл не существует, он будет
   * создан.
   *
   * @note Функция использует Qt-классы QFile и QTextStream.
   */
  void addRecordToFile(const Student &student) {
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
};
/**
 * @brief Точка входа для приложения.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код выхода приложения.
 */
int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  StudentApp studentApp;
  studentApp.show();

  return app.exec();
}
#include "main.moc"