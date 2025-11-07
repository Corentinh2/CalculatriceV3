#ifndef CALCULATRICEV3_H
#define CALCULATRICEV3_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatriceV3; }
QT_END_NAMESPACE

class CalculatriceV3 : public QWidget
{
    Q_OBJECT

private:
    Ui::CalculatriceV3 *ui;
    int NB_TOUCHES;
    QPushButton **touches;
    QGridLayout *grille;
    QLineEdit *afficheur;

public:
    CalculatriceV3(QWidget *parent = nullptr);
    ~CalculatriceV3();
    void onQPushButtonClicked();
};
#endif // CALCULATRICEV3_H
