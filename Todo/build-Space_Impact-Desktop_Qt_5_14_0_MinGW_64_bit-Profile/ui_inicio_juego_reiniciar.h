/********************************************************************************
** Form generated from reading UI file 'inicio_juego_reiniciar.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_JUEGO_REINICIAR_H
#define UI_INICIO_JUEGO_REINICIAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inicio_juego_reiniciar
{
public:
    QLineEdit *le_clave;
    QPushButton *btn_crear;
    QLineEdit *le_usuario;

    void setupUi(QWidget *Inicio_juego_reiniciar)
    {
        if (Inicio_juego_reiniciar->objectName().isEmpty())
            Inicio_juego_reiniciar->setObjectName(QString::fromUtf8("Inicio_juego_reiniciar"));
        Inicio_juego_reiniciar->resize(603, 415);
        le_clave = new QLineEdit(Inicio_juego_reiniciar);
        le_clave->setObjectName(QString::fromUtf8("le_clave"));
        le_clave->setGeometry(QRect(320, 250, 211, 41));
        QFont font;
        font.setPointSize(12);
        le_clave->setFont(font);
        btn_crear = new QPushButton(Inicio_juego_reiniciar);
        btn_crear->setObjectName(QString::fromUtf8("btn_crear"));
        btn_crear->setGeometry(QRect(400, 350, 181, 41));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        btn_crear->setFont(font1);
        le_usuario = new QLineEdit(Inicio_juego_reiniciar);
        le_usuario->setObjectName(QString::fromUtf8("le_usuario"));
        le_usuario->setGeometry(QRect(40, 250, 211, 41));
        le_usuario->setFont(font);

        retranslateUi(Inicio_juego_reiniciar);

        QMetaObject::connectSlotsByName(Inicio_juego_reiniciar);
    } // setupUi

    void retranslateUi(QWidget *Inicio_juego_reiniciar)
    {
        Inicio_juego_reiniciar->setWindowTitle(QCoreApplication::translate("Inicio_juego_reiniciar", "Form", nullptr));
        le_clave->setText(QString());
        btn_crear->setText(QCoreApplication::translate("Inicio_juego_reiniciar", "Reiniciar registro", nullptr));
        le_usuario->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Inicio_juego_reiniciar: public Ui_Inicio_juego_reiniciar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_JUEGO_REINICIAR_H
