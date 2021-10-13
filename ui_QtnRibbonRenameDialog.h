/********************************************************************************
** Form generated from reading UI file 'QtnRibbonRenameDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTNRIBBONRENAMEDIALOG_H
#define UI_QTNRIBBONRENAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RibbonRenameDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutTop;
    QLabel *label;
    QLineEdit *lineEditName;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayoutBottom;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RibbonRenameDialog)
    {
        if (RibbonRenameDialog->objectName().isEmpty())
            RibbonRenameDialog->setObjectName(QString::fromUtf8("RibbonRenameDialog"));
        RibbonRenameDialog->resize(278, 79);
        horizontalLayout_3 = new QHBoxLayout(RibbonRenameDialog);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, 0);
        horizontalLayoutTop = new QHBoxLayout();
        horizontalLayoutTop->setObjectName(QString::fromUtf8("horizontalLayoutTop"));
        horizontalLayoutTop->setSizeConstraint(QLayout::SetNoConstraint);
        label = new QLabel(RibbonRenameDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayoutTop->addWidget(label);

        lineEditName = new QLineEdit(RibbonRenameDialog);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayoutTop->addWidget(lineEditName);

        horizontalLayoutTop->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayoutTop);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayoutBottom = new QHBoxLayout();
        horizontalLayoutBottom->setObjectName(QString::fromUtf8("horizontalLayoutBottom"));
        horizontalLayoutBottom->setSizeConstraint(QLayout::SetDefaultConstraint);
        buttonBox = new QDialogButtonBox(RibbonRenameDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayoutBottom->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayoutBottom);

        verticalLayout->setStretch(2, 1);

        horizontalLayout_3->addLayout(verticalLayout);

#if QT_CONFIG(shortcut)
        label->setBuddy(lineEditName);
#endif // QT_CONFIG(shortcut)

        retranslateUi(RibbonRenameDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RibbonRenameDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RibbonRenameDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RibbonRenameDialog);
    } // setupUi

    void retranslateUi(QDialog *RibbonRenameDialog)
    {
        RibbonRenameDialog->setWindowTitle(QCoreApplication::translate("RibbonRenameDialog", "Rename", nullptr));
        label->setText(QCoreApplication::translate("RibbonRenameDialog", "&Display Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RibbonRenameDialog: public Ui_RibbonRenameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTNRIBBONRENAMEDIALOG_H
