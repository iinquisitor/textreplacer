#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("зᴀᴍᴇʜᴀ тᴇᴋᴄтᴀ");
    connect(ui->replace_button, &QPushButton::clicked, this, &MainWindow::replaceText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replaceText()
{
    QString inputText = ui->input_text->toPlainText();
    QString replacedText = replaceLetters(inputText);
    ui->output_text->setPlainText(replacedText);
}

QString MainWindow::replaceLetters(const QString &text)
{
    QString result = text;

    // Английский алфавит
    QString englishAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    QString englishReplacedFormat = "ᴀʙᴄᴅᴇғɢʜɪᴊᴋʟᴍɴᴏᴘqʀsᴛᴜᴠᴡxʏᴢᴀʙᴄᴅᴇғɢʜɪᴊᴋʟᴍɴᴏᴘqʀsᴛᴜᴠᴡxʏᴢ";

    // Проверка на совпадение длины
    if (englishAlphabet.length() != englishReplacedFormat.length()) {
        qWarning() << "Длины английского алфавита и формата замены не совпадают!";
        return result; // Возвращаем исходный текст
    }

    for (int i = 0; i < englishAlphabet.length(); ++i) {
        QChar letter = englishAlphabet[i];
        QChar formatLetter = englishReplacedFormat[i];

        // Сначала заменяем на строчную букву
        result.replace(letter, letter.toLower());
        // Затем заменяем на форматированную букву
        result.replace(letter.toLower(), formatLetter);
    }

    // Русский алфавит
    QString russianAlphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    QString russianReplacedFormat = "ᴀбʙгдᴇёжзийᴋлᴍʜᴏпᴘᴄтуȹxцчшщъыьэюяᴀбʙгдᴇёжзийᴋлᴍʜᴏпᴘᴄтуȹxцчшщъыьэюя";

    // Проверка на совпадение длины
    if (russianAlphabet.length() != russianReplacedFormat.length()) {
        qWarning() << "Длины русского алфавита и формата замены не совпадают!";
        return result; // Возвращаем исходный текст
    }

    for (int i = 0; i < russianAlphabet.length(); ++i) {
        QChar letter = russianAlphabet[i];
        QChar formatLetter = russianReplacedFormat[i];

        // Сначала заменяем на строчную букву
        result.replace(letter, letter.toLower());
        // Затем заменяем на форматированную букву
        result.replace(letter.toLower(), formatLetter);
    }

    // Украинский алфавит
    QString ukrainianAlphabet = "АБВГҐДЕЄЖЗИЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯабвгґдеєжзиїйклмнопрстуфхцчшщьюя";
    QString ukrainianReplacedFormat = "ᴀбʙгґдᴇєжзиїйᴋлᴍʜᴏпᴘᴄтуȹxцчшщьюяᴀбʙгґдᴇєжзиїйᴋлᴍʜᴏпᴘᴄтуȹxцчшщьюя";

    // Проверка на совпадение длины
    if (ukrainianAlphabet.length() != ukrainianReplacedFormat.length()) {
        qWarning() << "Длины украинского алфавита и формата замены не совпадают!";
        return result; // Возвращаем исходный текст
    }

    for (int i = 0; i < ukrainianAlphabet.length(); ++i) {
        QChar letter = ukrainianAlphabet[i];
        QChar formatLetter = ukrainianReplacedFormat[i];

        // Сначала заменяем на строчную букву
        result.replace(letter, letter.toLower());
        // Затем заменяем на форматированную букву
        result.replace(letter.toLower(), formatLetter);
    }

    return result;
}
