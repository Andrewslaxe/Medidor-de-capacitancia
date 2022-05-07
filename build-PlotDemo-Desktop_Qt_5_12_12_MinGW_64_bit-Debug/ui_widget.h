/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QLabel *label_10;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_11;
    QLabel *label_12;
    QProgressBar *Porcentual;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_14;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(781, 334);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 80, 399, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 0));
        label_3->setMaximumSize(QSize(57, 16777215));
        QFont font;
        font.setPointSize(13);
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(100, 0));
        comboBox->setFont(font);

        horizontalLayout_2->addWidget(comboBox);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        horizontalLayout_2->addWidget(pushButton_3);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 0, 551, 41));
        QFont font1;
        font1.setPointSize(25);
        label_5->setFont(font1);
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(640, 0, 131, 16));
        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(410, 80, 331, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(horizontalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(0, 0));
        label_11->setMaximumSize(QSize(57, 16777215));
        label_11->setFont(font);

        horizontalLayout_3->addWidget(label_11);

        label_12 = new QLabel(horizontalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(0, 0));
        label_12->setMaximumSize(QSize(500, 16777215));
        label_12->setFont(font);

        horizontalLayout_3->addWidget(label_12);

        Porcentual = new QProgressBar(Widget);
        Porcentual->setObjectName(QString::fromUtf8("Porcentual"));
        Porcentual->setGeometry(QRect(60, 180, 531, 51));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Porcentual->sizePolicy().hasHeightForWidth());
        Porcentual->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(50);
        font2.setBold(false);
        font2.setWeight(50);
        Porcentual->setFont(font2);
        Porcentual->setMaximum(333);
        Porcentual->setValue(0);
        Porcentual->setInvertedAppearance(false);
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(true);
        pushButton_4->setGeometry(QRect(430, 190, 131, 41));
        QFont font3;
        font3.setPointSize(15);
        pushButton_4->setFont(font3);
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(590, 190, 131, 41));
        pushButton_5->setFont(font3);
        label_13 = new QLabel(Widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(60, 240, 351, 31));
        label_13->setMinimumSize(QSize(0, 0));
        label_13->setMaximumSize(QSize(500, 16777215));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(Widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(490, 240, 261, 31));
        label_15->setMinimumSize(QSize(0, 0));
        label_15->setMaximumSize(QSize(500, 16777215));
        label_15->setFont(font);
        label_16 = new QLabel(Widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(490, 270, 261, 21));
        label_16->setMinimumSize(QSize(0, 0));
        label_16->setMaximumSize(QSize(500, 16777215));
        label_16->setFont(font);
        label_17 = new QLabel(Widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(490, 300, 261, 21));
        label_17->setMinimumSize(QSize(0, 0));
        label_17->setMaximumSize(QSize(500, 16777215));
        label_17->setFont(font);
        label_14 = new QLabel(Widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(60, 280, 351, 31));
        label_14->setMinimumSize(QSize(0, 0));
        label_14->setMaximumSize(QSize(500, 16777215));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "RPM & Corriente CACD", nullptr));
        label_3->setText(QApplication::translate("Widget", "Puerto:", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "Abrir", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "Actualizar", nullptr));
        label_5->setText(QApplication::translate("Widget", "CARGA Y DESCARGA DEL CAPACITOR", nullptr));
        label_10->setText(QApplication::translate("Widget", "Designed By: Jaime Peraza", nullptr));
        label_11->setText(QApplication::translate("Widget", "Status:", nullptr));
        label_12->setText(QString());
        Porcentual->setFormat(QString());
        pushButton_4->setText(QApplication::translate("Widget", "Cargar", nullptr));
        pushButton_5->setText(QApplication::translate("Widget", "Descargar", nullptr));
        label_13->setText(QApplication::translate("Widget", "Voltaje Actual: ", nullptr));
        label_15->setText(QApplication::translate("Widget", "Tiempo Tao:", nullptr));
        label_16->setText(QApplication::translate("Widget", "Tiempo de descarga:", nullptr));
        label_17->setText(QApplication::translate("Widget", "Capacitancia:", nullptr));
        label_14->setText(QApplication::translate("Widget", "Porcentaje de carga:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
