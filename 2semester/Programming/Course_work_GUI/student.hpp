#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <QString>
#include <QVector>
/**
 * @brief Структура для представления информации о предмете.
 */
struct Subject {
    QString name;
    int grade;
};
/**
 * @brief Структура для представления информации о студенте.
 */
struct Student {
    QString lastName;           ///< Фамилия студента.
    QString firstName;          ///< Имя студента.
    QString patronymic;         ///< Отчество студента.
    QVector<Subject> subjects;  //< Вектор с информацией о предметах студента.
    [[nodiscard]] QString toString() const;
};

#endif // STUDENT_HPP
