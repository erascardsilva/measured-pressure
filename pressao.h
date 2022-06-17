#ifndef PRESSAO_H
#define PRESSAO_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>


QT_BEGIN_NAMESPACE
namespace Ui { class pressao; }
QT_END_NAMESPACE

class pressao : public QMainWindow
{
    Q_OBJECT

public:
    pressao(QWidget *parent = nullptr);
    ~pressao();

private slots:
    void on_actionSair_triggered();

    void on_actionSobre_triggered();

    void on_btn_gravar_clicked();

    void on_btn_ver_clicked();

    void on_pushButton_clicked();

    void on_actionVerificar_triggered();

    void on_actionMedir_triggered();

private:
    Ui::pressao *ui;
};
#endif // PRESSAO_H
