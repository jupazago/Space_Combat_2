/********************************************************************************
** Form generated from reading UI file 'inicio_juego_cargar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_JUEGO_CARGAR_H
#define UI_INICIO_JUEGO_CARGAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inicio_juego_cargar
{
public:
    QLineEdit *le_clave;
    QPushButton *btn_cargar;
    QLineEdit *le_usuario;

    void setupUi(QWidget *inicio_juego_cargar)
    {
        if (inicio_juego_cargar->objectName().isEmpty())
            inicio_juego_cargar->setObjectName(QString::fromUtf8("inicio_juego_cargar"));
        inicio_juego_cargar->resize(603, 415);
        le_clave = new QLineEdit(inicio_juego_cargar);
        le_clave->setObjectName(QString::fromUtf8("le_clave"));
        le_clave->setGeometry(QRect(320, 250, 211, 41));
        QFont font;
        font.setPointSize(12);
        le_clave->setFont(font);
        btn_cargar = new QPushButton(inicio_juego_cargar);
        btn_cargar->setObjectName(QString::fromUtf8("btn_cargar"));
        btn_cargar->setGeometry(QRect(400, 350, 181, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        btn_cargar->setFont(font1);
        le_usuario = new QLineEdit(inicio_juego_cargar);
        le_usuario->setObjectName(QString::fromUtf8("le_usuario"));
        le_usuario->setGeometry(QRect(40, 250, 211, 41));
        le_usuario->setFont(font);

        retranslateUi(inicio_juego_cargar);

        QMetaObject::connectSlotsByName(inicio_juego_cargar);
    } // setupUi

    void retranslateUi(QWidget *inicio_juego_cargar)
    {
        inicio_juego_cargar->setWindowTitle(QCoreApplication::translate("inicio_juego_cargar", "Form", nullptr));
        le_clave->setText(QString());
        btn_cargar->setText(QCoreApplication::translate("inicio_juego_cargar", "Cargar", nullptr));
        le_usuario->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class inicio_juego_cargar: public Ui_inicio_juego_cargar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_JUEGO_CARGAR_H
