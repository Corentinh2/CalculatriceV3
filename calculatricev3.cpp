#include "calculatricev3.h"
#include "ui_calculatricev3.h"
#include <qjsengine.h>

CalculatriceV3::CalculatriceV3(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalculatriceV3)
    , NB_TOUCHES(16)
{
    ui->setupUi(this);
    const QString tableDesSymboles[ ] = {"7", "8", "9", "+" ,"4", "5", "6", "-", "1", "2", "3", "*",
                                         "C", "0", "=", "/"};
    grille = new QGridLayout;
    afficheur = new QLineEdit;
    afficheur->setMinimumHeight(50);
    afficheur->setStyleSheet("background-color: rgb(143, 240, 164);");
    touches = new QPushButton*[NB_TOUCHES];
    grille->addWidget(afficheur,0,0,1,4);
    this->setLayout(grille);
    int ligne = 1;
    int colonne = 0;

    for(int i = 0; i < NB_TOUCHES; i++)
    {
        touches[i] = new QPushButton(tableDesSymboles[i]);
        touches[i]->setText(tableDesSymboles[i]);
        touches[i]->setMinimumSize(50, 50);
        grille->addWidget(touches[i], ligne, colonne);
        connect(touches[i], &QPushButton::clicked, this, &CalculatriceV3::onQPushButtonClicked);
        colonne++;
        if(colonne == 4)
        {
            colonne = 0;
            ligne++;
        }
    }

    this->setLayout(grille);
}


CalculatriceV3::~CalculatriceV3()
{
    delete ui;
}

void CalculatriceV3::onQPushButtonClicked()
{
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());

    if(touche){
        QString texte = touche->text();

        if(texte == "C"){
            afficheur->clear();
        }
        else{
            if (texte == "="){
                QString expression = afficheur->text();
                QJSEngine myEngine;
                QJSValue resultat = myEngine.evaluate(expression);
                afficheur->setText(resultat.toString());
            }

            else{
                afficheur->setText(afficheur->text()+texte);
            }
        }
    }
}
