#include "pressao.h"
#include "ui_pressao.h"
#include "pressao.h"



pressao::pressao(QWidget *parent): QMainWindow(parent), ui(new Ui::pressao){

    ui->setupUi(this);
    QSqlDatabase dbpressao = QSqlDatabase::addDatabase("QSQLITE");
    QString path = getenv("HOME");
    path += "/pressao.db";
    dbpressao.setDatabaseName( path );

    if ( !dbpressao.open() ){
        ui->label_status->setText("Banco de dados não aberto !!!");

    }else{

        ui->label_status->setText("Banco de dados conectado com Sucesso!!");
}
}

pressao::~pressao()
{
    delete ui;
}


void pressao::on_actionSair_triggered(){
    close();

}


void pressao::on_actionSobre_triggered(){

    QMessageBox::about(this , "Sobre" , "Progarma desenvolvido para\n"
                                        "registros e verificação posterior da sua \n"
                                        "pressão arterial....\n"
                                        "Programador | Erasmo Cardoso");
}


void pressao::on_btn_gravar_clicked(){

        QSqlQuery query;
        QString sql = "INSERT INTO dados (nome, maxima, minima, data_press) VALUES ('" + ui->line_nome->text() + "', '" + ui->line_pmax->text() + "', '" + ui->line_pmin->text() + "',' " + ui->line_data->text() + " ')";
        query.prepare( sql );

        if (  query.exec() ){
            QMessageBox::information(this, "Sucesso", "Dados Gravados");
            ui->line_nome->clear();
            ui->line_pmax->clear();
            ui->line_pmin->clear();
            ui->line_data->clear();
            ui->line_nome->setFocus();
        }else{
            QMessageBox::critical(this, "Erro", "Não Gravado");
        }

}




void pressao::on_btn_ver_clicked(){

    QSqlQuery query;
    QString sql = "SELECT * FROM  dados";
    query.prepare( sql);

    if( query.exec() ){

        int i = 0;
        ui->table_lista->setColumnCount( 4 );

        while ( query.next() ){
            ui->table_lista->insertRow( i );
            ui->table_lista->setItem( i, 0, new QTableWidgetItem( query.value( 0 ) .toString())) ;
            ui->table_lista->setItem( i, 1, new QTableWidgetItem( query.value( 1 ) .toString())) ;
            ui->table_lista->setItem( i, 2, new QTableWidgetItem( query.value( 2 ) .toString())) ;
            ui->table_lista->setItem( i, 3, new QTableWidgetItem( query.value( 3 ) .toString())) ;
            ui->table_lista->setRowHeight( i , 30);
            i++;
        }
        }
        }




void pressao::on_pushButton_clicked(){

    ui->table_lista->clear();

}


void pressao::on_actionVerificar_triggered(){


    QSqlQuery query;
    QString sql = "SELECT * FROM  dados";
    query.prepare( sql);

    if( query.exec() ){

        int i = 0;
        ui->table_lista->setColumnCount( 4 );

        while ( query.next() ){
            ui->table_lista->insertRow( i );
            ui->table_lista->setItem( i, 0, new QTableWidgetItem( query.value( 0 ) .toString())) ;
            ui->table_lista->setItem( i, 1, new QTableWidgetItem( query.value( 1 ) .toString())) ;
            ui->table_lista->setItem( i, 2, new QTableWidgetItem( query.value( 2 ) .toString())) ;
            ui->table_lista->setItem( i, 3, new QTableWidgetItem( query.value( 3 ) .toString())) ;
            ui->table_lista->setRowHeight( i , 30);
            i++;
        }
        }
        }




void pressao::on_actionMedir_triggered(){


    QSqlQuery query;
    QString sql = "INSERT INTO dados (nome, maxima, minima, data_press) VALUES ('" + ui->line_nome->text() + "', '" + ui->line_pmax->text() + "', '" + ui->line_pmin->text() + "',' " + ui->line_data->text() + " ')";
    query.prepare( sql );

    if (  query.exec() ){
        QMessageBox::information(this, "Sucesso", "Dados Gravados");
        ui->line_nome->clear();
        ui->line_pmax->clear();
        ui->line_pmin->clear();
        ui->line_data->clear();
        ui->line_nome->setFocus();
    }else{
        QMessageBox::critical(this, "Erro", "Não Gravado");
    }


}

