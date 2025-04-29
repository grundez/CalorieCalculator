#include <QCoreApplication>
#include <QTextStream>
#include <QMap>
#include <QString>
#include "caloriecalculator.h"

QTextStream cout(stdout);
QTextStream cin(stdin);

int getIntInput(const QString& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cout.flush();

        QString input = cin.readLine();
        bool ok;
        value = input.toInt(&ok);

        if (ok && value >= min && value <= max) {
            return value;
        }

        cout << QString("Ошибка! Введите число от %1 до %2\n").arg(min).arg(max);
    }
}

void displayMenu() {
    cout << "\n=== Учет калорий ===\n"
         << "1. Добавить запись\n"
         << "2. Удалить запись\n"
         << "3. Показать все записи\n"
         << "4. Рассчитать баланс\n"
         << "5. Выход\n";
}

void addEntry(CalorieCalculator& calculator) {
    cout << "\nДобавить:\n"
         << "1. Еда\n"
         << "2. Активность\n";

    int typeChoice = getIntInput("Выберите тип: ", 1, 2);
    EntryType type = (typeChoice == 1) ? EntryType::Food : EntryType::Activity;

    cout << "Введите название: ";
    cout.flush();
    QString name = cin.readLine();

    int calories = getIntInput("Введите калории: ", 0, 10000);

    calculator.addEntry(name, calories, type);
    cout << "Запись добавлена!\n";
}

void removeEntry(CalorieCalculator& calculator) {
    cout << "\nУдалить:\n"
         << "1. Еда\n"
         << "2. Активность\n";

    int typeChoice = getIntInput("Выберите тип: ", 1, 2);
    EntryType type = (typeChoice == 1) ? EntryType::Food : EntryType::Activity;

    cout << "Введите название для удаления: ";
    cout.flush();
    QString name = cin.readLine();

    if (calculator.removeEntry(name, type)) {
        cout << QString("Запись '%1' успешно удалена!\n").arg(name);
    } else {
        cout << QString("Запись '%1' не найдена!\n").arg(name);
    }
}

void showEntries(const CalorieCalculator& calculator) {
    cout << "\n=== Текущие записи ===\n";

    cout << "Еда:\n";
    const QMap<QString, int>& foods = calculator.getEntries(EntryType::Food);
    if (foods.isEmpty()) {
        cout << "  Нет записей\n";
    } else {
        for (auto it = foods.constBegin(); it != foods.constEnd(); ++it) {
            cout << QString("  %1: %2 ккал\n").arg(it.key()).arg(it.value());
        }
    }

    cout << "Активности:\n";
    const QMap<QString, int>& activities = calculator.getEntries(EntryType::Activity);
    if (activities.isEmpty()) {
        cout << "  Нет записей\n";
    } else {
        for (auto it = activities.constBegin(); it != activities.constEnd(); ++it) {
            cout << QString("  %1: %2 ккал\n").arg(it.key()).arg(it.value());
        }
    }
}

void showBalance(const CalorieCalculator& calculator) {
    int balance = calculator.calculateCalorieBalance();

    if (balance > 0) {
        cout << QString("Избыток калорий: %1 ккал\n").arg(balance);
    } else if (balance < 0) {
        cout << QString("Дефицит калорий: %1 ккал\n").arg(qAbs(balance));
    } else {
        cout << "Баланс калорий идеален: 0 ккал\n";
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);


    CalorieCalculator calculator;

    while (true) {
        displayMenu();
        int choice = getIntInput("Выберите действие: ", 1, 5);

        switch (choice) {
        case 1: addEntry(calculator); break;
        case 2: removeEntry(calculator); break;
        case 3: showEntries(calculator); break;
        case 4: showBalance(calculator); break;
        case 5: return 0;
        default: cout << "Неверный выбор!\n";
        }
    }

    return a.exec();
}
