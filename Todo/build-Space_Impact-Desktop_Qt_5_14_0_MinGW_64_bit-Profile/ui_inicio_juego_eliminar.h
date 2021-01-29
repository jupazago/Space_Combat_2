/********************************************************************************
** Form generated from reading UI file 'inicio_juego_eliminar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_JUEGO_ELIMINAR_H
#define UI_INICIO_JUEGO_ELIMINAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inicio_juego_eliminar
{
public:
    QLineEdit *le_usuario;
    QPushButton *btn_eliminar;
    QLineEdit *le_clave;

    void setupUi(QWidget *Inicio_juego_eliminar)
    {
        if (Inicio_juego_eliminar->objectName().isEmpty())
            Inicio_juego_eliminar->setObjectName(QString::fromUtf8("Inicio_juego_eliminar"));
        Inicio_juego_eliminar->resize(603, 415);
        le_usuario = new QLineEdit(Inicio_juego_eliminar);
        le_usuario->setObjectName(QString::fromUtf8("le_usuario"));
        le_usuario->setGeometry(QRect(30, 250, 211, 41));
        QFont font;
        font.setPointSize(12);
        le_usuario->setFont(font);
        btn_eliminar = new QPushButton(Inicio_juego_eliminar);
        btn_eliminar->setObjectName(QString::fromUtf8("btn_eliminar"));
        btn_eliminar->setGeometry(QRect(390, 350, 181, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        btn_eliminar->setFont(font1);
        le_clave = new QLineEdit(Inicio_juego_eliminar);
        le_clave->setObjectName(QString::fromUtf8("le_clave"));
        le_clave->setGeometry(QRect(310, 250, 211, 41));
        le_clave->setFont(font);

        retranslateUi(Inicio_juego_eliminar);

        QMetaObject::connectSlotsByName(Inicio_juego_eliminar);
    } // setupUi

    void retranslateUi(QWidget *Inicio_juego_eliminar)
    {
        Inicio_juego_eliminar->setWindowTitle(QCoreApplication::translate("Inicio_juego_eliminar", "Form", nullptr));
        le_usuario->setText(QString());
        btn_eliminar->setText(QCoreApplication::translate("Inicio_juego_eliminar", "Eliminar Registro", nullptr));
        le_clave->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Inicio_juego_eliminar: public Ui_Inicio_juego_eliminar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_JUEGO_ELIMINAR_H
