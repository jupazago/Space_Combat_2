/********************************************************************************
** Form generated from reading UI file 'inicio_juego_nuevo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_JUEGO_NUEVO_H
#define UI_INICIO_JUEGO_NUEVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inicio_juego_nuevo
{
public:
    QPushButton *btn_crear;
    QLineEdit *le_usuario;
    QLineEdit *le_clave;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Inicio_juego_nuevo)
    {
        if (Inicio_juego_nuevo->objectName().isEmpty())
            Inicio_juego_nuevo->setObjectName(QString::fromUtf8("Inicio_juego_nuevo"));
        Inicio_juego_nuevo->resize(603, 415);
        btn_crear = new QPushButton(Inicio_juego_nuevo);
        btn_crear->setObjectName(QString::fromUtf8("btn_crear"));
        btn_crear->setGeometry(QRect(400, 350, 181, 41));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        btn_crear->setFont(font);
        le_usuario = new QLineEdit(Inicio_juego_nuevo);
        le_usuario->setObjectName(QString::fromUtf8("le_usuario"));
        le_usuario->setGeometry(QRect(40, 250, 211, 41));
        QFont font1;
        font1.setPointSize(12);
        le_usuario->setFont(font1);
        le_clave = new QLineEdit(Inicio_juego_nuevo);
        le_clave->setObjectName(QString::fromUtf8("le_clave"));
        le_clave->setGeometry(QRect(320, 250, 211, 41));
        le_clave->setFont(font1);
        label = new QLabel(Inicio_juego_nuevo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 210, 111, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAutoFillBackground(false);
        label_2 = new QLabel(Inicio_juego_nuevo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 210, 111, 31));
        label_2->setFont(font2);
        label_2->setAutoFillBackground(false);

        retranslateUi(Inicio_juego_nuevo);

        QMetaObject::connectSlotsByName(Inicio_juego_nuevo);
    } // setupUi

    void retranslateUi(QWidget *Inicio_juego_nuevo)
    {
        Inicio_juego_nuevo->setWindowTitle(QCoreApplication::translate("Inicio_juego_nuevo", "Form", nullptr));
        btn_crear->setText(QCoreApplication::translate("Inicio_juego_nuevo", "Crear y jugar", nullptr));
        le_usuario->setText(QString());
        le_clave->setText(QString());
        label->setText(QCoreApplication::translate("Inicio_juego_nuevo", "Usuario", nullptr));
        label_2->setText(QCoreApplication::translate("Inicio_juego_nuevo", "Clave", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inicio_juego_nuevo: public Ui_Inicio_juego_nuevo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_JUEGO_NUEVO_H
