/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inicio
{
public:
    QPushButton *btn_nuevo;
    QPushButton *btn_cargar;
    QPushButton *btn_eliminar;
    QPushButton *btn_reiniciar;

    void setupUi(QWidget *Inicio)
    {
        if (Inicio->objectName().isEmpty())
            Inicio->setObjectName(QString::fromUtf8("Inicio"));
        Inicio->resize(594, 464);
        btn_nuevo = new QPushButton(Inicio);
        btn_nuevo->setObjectName(QString::fromUtf8("btn_nuevo"));
        btn_nuevo->setGeometry(QRect(220, 250, 161, 31));
        QPalette palette;
        QBrush brush(QColor(0, 134, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_nuevo->setPalette(palette);
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        btn_nuevo->setFont(font);
        btn_cargar = new QPushButton(Inicio);
        btn_cargar->setObjectName(QString::fromUtf8("btn_cargar"));
        btn_cargar->setGeometry(QRect(220, 300, 161, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_cargar->setPalette(palette1);
        btn_cargar->setFont(font);
        btn_eliminar = new QPushButton(Inicio);
        btn_eliminar->setObjectName(QString::fromUtf8("btn_eliminar"));
        btn_eliminar->setGeometry(QRect(220, 350, 161, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_eliminar->setPalette(palette2);
        btn_eliminar->setFont(font);
        btn_reiniciar = new QPushButton(Inicio);
        btn_reiniciar->setObjectName(QString::fromUtf8("btn_reiniciar"));
        btn_reiniciar->setGeometry(QRect(220, 400, 161, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        btn_reiniciar->setPalette(palette3);
        btn_reiniciar->setFont(font);

        retranslateUi(Inicio);

        QMetaObject::connectSlotsByName(Inicio);
    } // setupUi

    void retranslateUi(QWidget *Inicio)
    {
        Inicio->setWindowTitle(QCoreApplication::translate("Inicio", "Form", nullptr));
        btn_nuevo->setText(QCoreApplication::translate("Inicio", "Juego Nuevo", nullptr));
        btn_cargar->setText(QCoreApplication::translate("Inicio", "Cargar partida", nullptr));
        btn_eliminar->setText(QCoreApplication::translate("Inicio", "Eliminar juego", nullptr));
        btn_reiniciar->setText(QCoreApplication::translate("Inicio", "Reiniciar juego", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inicio: public Ui_Inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
