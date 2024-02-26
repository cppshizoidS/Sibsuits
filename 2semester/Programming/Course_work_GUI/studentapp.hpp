#ifndef STUDENTAPP_HPP
#define STUDENTAPP_HPP

#include <QMainWindow>
#include "student.hpp"
/**
 * @brief StudentApp класс для управления записями учащихся
 */
class StudentApp : public QMainWindow {
    Q_OBJECT
/**
   * @brief Конструктор класса StudentApp.
   * @param parent Родительский виджет.
   */
public:
    explicit StudentApp(QWidget *parent = nullptr);

private slots:
    void createFile();
    void addRecord();
    void createIndexFiles();
    void viewFile();
    void searchAndUpdateRecord();
    void deleteRecord();

private:
    const int max_record = 4;
    QString filename = "students.txt";

    void setupUi();
    void addRecordToFile(const Student &student);
};

#endif // STUDENTAPP_H
