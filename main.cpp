#include "mainwindow.h"

#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>

#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    //Set a blank image to 200 x 200 pixels
    QPixmap SplashImage(200,200);

    //Fill the images with a white color
    SplashImage.fill(Qt::white);

    SplashImage.fill(Qt::red);

    //Create a splashscreen image and hold the image on top of all other windows
    QSplashScreen HangmanSplashScreen(SplashImage, Qt::WindowStaysOnTopHint);

    //Display spash screen
    HangmanSplashScreen.show();

    //add text "Loading Hangman..." to the splashscreen
    HangmanSplashScreen.showMessage("Loading Hangman...");

    //HangmanSplashScreen.showMessage("New Message");

    //Hold Splashscreen open until user clicks mouse
    //a.processEvents();
    //If used will hold the splashscreen on the screen for 5 seconds
    QTimer::singleShot(5000, &HangmanSplashScreen, SLOT(close())); // keep displayed for 5 seconds
    QTimer::singleShot(5000, &w, SLOT(show()));
    //w.show();

    return a.exec();
}
