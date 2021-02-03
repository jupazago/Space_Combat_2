/********************************************************************************
** Form generated from reading UI file 'inicio_juego_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_JUEGO_MENU_H
#define UI_INICIO_JUEGO_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inicio_juego_menu
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *Inicio_juego_menu)
    {
        if (Inicio_juego_menu->objectName().isEmpty())
            Inicio_juego_menu->setObjectName(QString::fromUtf8("Inicio_juego_menu"));
        Inicio_juego_menu->resize(154, 136);
        pushButton = new QPushButton(Inicio_juego_menu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 121, 91));
        QFont font;
        font.setPointSize(11);
        pushButton->setFont(font);

        retranslateUi(Inicio_juego_menu);

        QMetaObject::connectSlotsByName(Inicio_juego_menu);
    } // setupUi

    void retranslateUi(QWidget *Inicio_juego_menu)
    {
        Inicio_juego_menu->setWindowTitle(QCoreApplication::translate("Inicio_juego_menu", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Inicio_juego_menu", "Men\303\272 Principal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inicio_juego_menu: public Ui_Inicio_juego_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_JUEGO_MENU_H
