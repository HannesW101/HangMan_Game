#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QString>
#include <QFile>
#include <cstdlib>
#include <ctime>
#include <iostream>

// global variables
std::vector<QString> EasyWords;
std::vector<QString> MediumWords;
std::vector<QString> HardWords;
std::vector<QLabel*> LetterLabels;
std::vector<QLabel*> WordLabels;
std::vector<QLabel*> BodyParts;
int GameState = 0;
int lengthOfWord;

// Function to read a CSV file and populate three vectors
void readCSV(const QString& filename,std::vector<QString>& easyWords,std::vector<QString>& mediumWords,std::vector<QString>& hardWords) {

    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening file:" << filename;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(';');

        if (parts.size() == 2) {
            QString word = parts[0].trimmed();
            int length = parts[1].toInt();

            if (length <= 6) {
                easyWords.push_back(word);
            } else if (length > 6 && length <= 9) {
                mediumWords.push_back(word);
            } else if (length > 9) {
                hardWords.push_back(word);
            }
        }
    }

    file.close();
}

// Function to pick a random index from a vector
int getRandomIndex(const std::vector<QString>& words) {
    if (words.empty()) {
        std::cerr << "Vector is empty, cannot pick a random index." << std::endl;
        return -1; // Return an invalid index or handle the error appropriately
    }

    // Seed the random number generator
    std::srand(std::time(0));

    // Generate a random index between 0 and the size of the vector
    int randomIndex = std::rand() % words.size();
    return randomIndex;
}

// Function to return a random word
QString getRandomWord(QString difficultyChoice){
    int randomIndex;
    if (difficultyChoice == "Easy"){
        randomIndex = getRandomIndex(EasyWords);
        return EasyWords[randomIndex];
    }else if(difficultyChoice == "Medium"){
        randomIndex = getRandomIndex(MediumWords);
        return MediumWords[randomIndex];
    }else{
        randomIndex = getRandomIndex(HardWords);
        return HardWords[randomIndex];
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // add items to cBdifficulty and set current index to 0 (Easy)
    ui->cBdifficulty->addItem("Easy");
    ui->cBdifficulty->addItem("Medium");
    ui->cBdifficulty->addItem("Hard");
    ui->cBdifficulty->setCurrentIndex(0);

    // populate LetterLabels vector
    LetterLabels.push_back(ui->lbl1);
    LetterLabels.push_back(ui->lbl2);
    LetterLabels.push_back(ui->lbl3);
    LetterLabels.push_back(ui->lbl4);
    LetterLabels.push_back(ui->lbl5);
    LetterLabels.push_back(ui->lbl6);
    LetterLabels.push_back(ui->lbl7);
    LetterLabels.push_back(ui->lbl8);
    LetterLabels.push_back(ui->lbl9);
    LetterLabels.push_back(ui->lbl10);
    LetterLabels.push_back(ui->lbl11);
    LetterLabels.push_back(ui->lbl12);
    LetterLabels.push_back(ui->lbl13);
    LetterLabels.push_back(ui->lbl14);
    LetterLabels.push_back(ui->lbl15);
    LetterLabels.push_back(ui->lbl16);
    LetterLabels.push_back(ui->lbl17);

    // populate WordLabels vector
    WordLabels.push_back(ui->Letter1);
    WordLabels.push_back(ui->Letter2);
    WordLabels.push_back(ui->Letter3);
    WordLabels.push_back(ui->Letter4);
    WordLabels.push_back(ui->Letter5);
    WordLabels.push_back(ui->Letter6);
    WordLabels.push_back(ui->Letter7);
    WordLabels.push_back(ui->Letter8);
    WordLabels.push_back(ui->Letter9);
    WordLabels.push_back(ui->Letter10);
    WordLabels.push_back(ui->Letter11);
    WordLabels.push_back(ui->Letter12);
    WordLabels.push_back(ui->Letter13);
    WordLabels.push_back(ui->Letter14);
    WordLabels.push_back(ui->Letter15);
    WordLabels.push_back(ui->Letter16);
    WordLabels.push_back(ui->Letter17);

    // populate BodyParts vector
    BodyParts.push_back(ui->lblHead);
    BodyParts.push_back(ui->lblBody);
    BodyParts.push_back(ui->lblArmRight);
    BodyParts.push_back(ui->lblArmLeft);
    BodyParts.push_back(ui->lblLegRight);
    BodyParts.push_back(ui->lblLegLeft);

    // hide/show all the labels initially
    for (int i = 0; i < LetterLabels.size(); i++){
        QLabel* letterLabel = LetterLabels[i];
        letterLabel->hide();

        QLabel* wordLabel = WordLabels[i];
        wordLabel->hide();
    }
    for (int j =0; j < BodyParts.size(); j++){
        QLabel* BodyPartsLabel = BodyParts[j];
        BodyPartsLabel->show();
    }

    ui->LeGuess->hide();
    ui->pBsubmitGuess->hide();
    ui->lWguesses->hide();
    ui->pBhint->hide();

    // call the function to read csv file and place words in their respective vectors
    readCSV(":/data/Words.csv",EasyWords,MediumWords,HardWords);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// button to start game
void MainWindow::on_pBstartGame_clicked()
{
    // set game state back to 0
    // set Correct Guesses to 0
    GameState = 0;
    ui->LeGuess->show();
    ui->pBsubmitGuess->show();
    ui->LeGuess->clear();
    ui->lblSetDifficulty->hide();
    ui->cBdifficulty->hide();
    ui->lWguesses->show();
    ui->lWguesses->clear();
    ui->pBhint->hide();

    // hide/show all the labels initially
    for (int i = 0; i < LetterLabels.size(); i++){
        QLabel* thisLabel = LetterLabels[i];
        thisLabel->hide();

        QLabel* wordLabel = WordLabels[i];
        wordLabel->hide();
        wordLabel->setText("1");
    }
    for (int j =0; j < BodyParts.size(); j++){
        QLabel* BodyPartsLabel = BodyParts[j];
        BodyPartsLabel->show();
    }

    QString DifficultyChoice = ui->cBdifficulty->currentText();
    // call function to return random word
    QString RandomWord = getRandomWord(DifficultyChoice);
    lengthOfWord = RandomWord.length();
    qDebug() << RandomWord;

    // iterate through characters in the word and display labels for the number of characters
    for (int i =0; i < RandomWord.length(); i++){
        QLabel* letterLabel = LetterLabels[i];
        letterLabel->show();

        // add each letter to an index of WordLabels
        QLabel* wordLabel = WordLabels[i];
        wordLabel->setText(RandomWord[i]);
    }
}

// button to guess a letter
int MainWindow::on_pBsubmitGuess_clicked(){

    QString guess = ui->LeGuess->text();

    // check if item exists in list widget
    bool itemAlreadyExists = false;
    for (int i = 0; i < ui->lWguesses->count(); ++i) {
        if (ui->lWguesses->item(i)->text() == guess) {
            ui->lblGuess->setText("You Have Already Guessed This Letter!");
            itemAlreadyExists = true;
            ui->LeGuess->clear();
            ui->LeGuess->setFocus();
            return 0;
        }
    }
    if (!itemAlreadyExists) {
        // Add the item if it doesn't already exist
        ui->lWguesses->addItem(guess);
    }

    // bool to check if the user got a guess correct
    bool correct = false;
    // loop through WordLabels and see if the users guess is in the word
    for (int i = 0; i < WordLabels.size(); i++){
        QLabel* wordLabel = WordLabels[i];

        // checks if the users guess is the current letter in the WordLabels vector
        if (guess == wordLabel->text()){
            wordLabel->show();
            // set guess to correct
            correct = true;
            // -1 from lengthOfWord for correct guesses
            lengthOfWord--;
        }
    }

    // display to label that guess is correct if guess is correct otherwise display guess is incorrect and call function to remove body part
    if (correct){
        ui->lblGuess->setText("You guessed correctly! :)");
    }else{
        ui->lblGuess->setText("You guessed incorrectly! :(");

        // display body part
        QLabel* BodyPartsLabel = BodyParts[GameState];
        BodyPartsLabel->hide();
        GameState++;
    }

    // check if game is over
    if (GameState > 5){
        ui->lblGuess->setText("Game Over You Lost!");
        ui->LeGuess->hide();
        ui->pBsubmitGuess->hide();
        ui->lblSetDifficulty->show();
        ui->pBstartGame->setText("Restart");
        ui->cBdifficulty->show();
        ui->lWguesses->hide();
        for (int i = 0; i < WordLabels.size(); i++){
            QLabel* wordLabel = WordLabels[i];
            if (wordLabel->text() != "1") wordLabel->show();
        }
    } else if(lengthOfWord == 0){
        ui->lblGuess->setText("Game Over You Won!");
        ui->LeGuess->hide();
        ui->pBsubmitGuess->hide();
        ui->lblSetDifficulty->show();
        ui->pBstartGame->setText("Restart");
        ui->cBdifficulty->show();
        ui->lWguesses->hide();
    }

    // check if the user needs a hint
    if (GameState == 2 || GameState == 5){
        ui->pBhint->show();
    }

    ui->LeGuess->clear();
    ui->LeGuess->setFocus();
}


int MainWindow::on_pBhint_clicked()
{
    ui->pBhint->hide();

    // first loop to find a suitable letter to show
    QString LetterToShow;
    for (int i = 0; i < WordLabels.size(); i++){
        QLabel* wordLabel = WordLabels[i];
        if (wordLabel->text() != "1" && wordLabel->isHidden() == true) {
            LetterToShow = wordLabel->text();
            break;
        }
    }

    // then loop again to show all occurences of that letter
    for (int i = 0; i < WordLabels.size(); i++){
        QLabel* wordLabel = WordLabels[i];
        if (wordLabel->text() == LetterToShow) {
            wordLabel->show();
            lengthOfWord--;
            ui->LeGuess->setFocus();
        }
    }

    // check if the user won from the hint
    if (lengthOfWord == 0){
        ui->lblGuess->setText("Game Over You Won!");
        ui->LeGuess->hide();
        ui->pBsubmitGuess->hide();
        ui->lblSetDifficulty->show();
        ui->pBstartGame->setText("Restart");
        ui->cBdifficulty->show();
        ui->lWguesses->hide();
    }
}

