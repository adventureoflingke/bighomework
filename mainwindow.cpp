#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdio>
#include <QMessageBox>
#include "my_class.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->Textout->clear();

    int kofl;

    kofl = ui->kind_of_loan->currentIndex();

    if(kofl==0||kofl==1)
    {
        int kofc;

        kofc = ui->kind_of_cal->currentIndex();

        if(kofc==0)
        {
            double are, up, mr, ir;//房屋面积与单价

            int my, pbw;

            are = ui->area->text().toDouble();

            up = ui->unit_price->text().toDouble();

            mr = ui->mortgage_rate1->text().toDouble();

            mr /= 10;

            ir = ui->interest_rate1->text().toDouble();

            ir /= 100;

            my = ui->mortgage_year->text().toInt();

            pbw = ui->pay_back_way->currentIndex();

            pbw++;

            if(my<=0)
            {
                ui->Textout->append("请输入正确的贷款年数，谢谢配合\n");

                return;
            }

            if(ir<=0)
            {
                ui->Textout->append("利率应大于零，这年头可没人做慈善\n");

                return;
            }

            if(are<0||up<0||are*up>=1e15)
            {
                ui->Textout->append("房屋数据异常，你真的不是在开玩笑吗？\n");

                return;
            }

            if(pbw==1)
            {
                l1c1p1 n(up,are,mr,my,ir);

                double fp = n.first_pay();

                ui->Textout->append("    首付(元)： "+QString::number(fp,10,0)+"\n");

                double mp = n.month_pay();

                ui->Textout->append("每月月供(元)： "+QString::number(mp,10,0)+"\n");

                double tl = n.total_loan();

                ui->Textout->append("贷款总额(元)： "+QString::number(tl,10,0)+"\n");

                double ip = n.interest_pay();

                ui->Textout->append("支付利息(元)： "+QString::number(ip,10,0)+"\n");

                double tp = n.total_pay();

                ui->Textout->append("还款总额(元)： "+QString::number(tp,10,0)+"\n");

                int mm = n.mortgage_month();

                ui->Textout->append("还款月数(月)： "+QString::number(mm)+"\n");
            }
            else if(pbw==2)
            {
                l1c1p2 n(up,are,mr,my,ir);

                double fp = n.first_pay();

                ui->Textout->append("    首付(元)： "+QString::number(fp,10,0)+"\n");

                double fmp = n.first_month_pay();

                ui->Textout->append("首月月供(元)： "+QString::number(fmp,10,0)+"\n");

                double emd = n.every_month_decrease();

                ui->Textout->append("每月递减(元)： "+QString::number(emd,10,0)+"\n");

                double tl = n.total_loan();

                ui->Textout->append("贷款总额(元)： "+QString::number(tl,10,0)+"\n");

                double ip = n.interest_pay();

                ui->Textout->append("支付利息(元)： "+QString::number(ip,10,0)+"\n");

                double tp = n.total_pay();

                ui->Textout->append("还款总额(元)： "+QString::number(tp,10,0)+"\n");

                int mm = n.mortgage_month();

                ui->Textout->append("还款月数(月)： "+QString::number(mm)+"\n");
            }
        }
        else if(kofc==1)
        {
            double tl, ir;

            int my, pbw;

            tl = ui->totalloan->text().toDouble();

            ir = ui->interest_rate2->text().toDouble();

            ir /= 100;

            my = ui->mortgage_year->text().toInt();

            pbw = ui->pay_back_way->currentIndex();

            pbw++;

            if(my<=0)
            {
                ui->Textout->append("请输入正确的贷款年数，谢谢配合\n");

                return;
            }

            if(ir<=0)
            {
                ui->Textout->append("利率应大于零，这年头可没人做慈善\n");

                return;
            }

            if(tl<0||tl>1e15)
            {
                ui->Textout->append("贷款总额异常，你是打算在火星上买房吗？\n");

                return;
            }

            if(pbw==1)
            {
                l1c2p1 n(tl,my,ir);

                double mp = n.month_pay();

                ui->Textout->append("每月月供(元)： "+QString::number(mp,10,0)+"\n");

                double tl = n.total_loan();

                ui->Textout->append("贷款总额(元)： "+QString::number(tl,10,0)+"\n");

                double ip = n.interest_pay();

                ui->Textout->append("支付利息(元)： "+QString::number(ip,10,0)+"\n");

                double tp = n.total_pay();

                ui->Textout->append("还款总额(元)： "+QString::number(tp,10,0)+"\n");

                int mm = n.mortgage_month();

                ui->Textout->append("还款月数(月)： "+QString::number(mm)+"\n");
            }
            else if(pbw==2)
            {
                l1c2p2 n(tl,my,ir);

                double fmp = n.first_month_pay();

                ui->Textout->append("首月月供(元)： "+QString::number(fmp,10,0)+"\n");

                double emd = n.every_month_decrease();

                ui->Textout->append("每月递减(元)： "+QString::number(emd,10,0)+"\n");

                double tl = n.total_loan();

                ui->Textout->append("贷款总额(元)： "+QString::number(tl,10,0)+"\n");

                double ip = n.interest_pay();

                ui->Textout->append("支付利息(元)： "+QString::number(ip,10,0)+"\n");

                double tp = n.total_pay();

                ui->Textout->append("还款总额(元)： "+QString::number(tp,10,0)+"\n");

                int mm = n.mortgage_month();

                ui->Textout->append("还款月数(月)： "+QString::number(mm)+"\n");
            }
        }
    }
    else if(kofl==2)
    {
        double bl, cl, bir, cir;

        int my, pbw;

        bl = ui->buss_loan->text().toDouble();

        bir = ui->buss_interest_rate->text().toDouble();

        bir /= 100;

        cl = ui->com_loan->text().toDouble();

        cir = ui->com_interest_rate->text().toDouble();

        cir /= 100;

        my = ui->mortgage_year->text().toInt();

        pbw = ui->pay_back_way->currentIndex();

        pbw++;

        if(my<=0)
        {
            ui->Textout->append("请输入正确的贷款年数，谢谢配合\n");

            return;
        }

        if(bir<=0||cir<=0)
        {
            ui->Textout->append("利率应大于零，这年头可没人做慈善\n");

            return;
        }

        if(bl<0||bl>1e15||cl<0||cl>1e15)
        {
            ui->Textout->append("贷款总额异常，你是打算在火星上买房吗？\n");

            return;
        }

        if(pbw==1)
        {
            l2p1 n(bl,bir,cl,cir,my);

            double mp = n.month_pay();

            ui->Textout->append("每月月供(元)： "+QString::number(mp,10,0)+"\n");

            double tl = n.total_loan();

            ui->Textout->append("贷款总额(元)： "+QString::number(tl,10,0)+"\n");

            double ip = n.interest_pay();

            ui->Textout->append("支付利息(元)： "+QString::number(ip,10,0)+"\n");

            double tp = n.total_pay();

            ui->Textout->append("还款总额(元)： "+QString::number(tp,10,0)+"\n");

            int mm = n.mortgage_month();

            ui->Textout->append("还款月数(月)： "+QString::number(mm)+"\n");
        }
        else if(pbw==2)
        {
            l2p2 n(bl,bir,cl,cir,my);

            double fmp = n.first_month_pay();

            ui->Textout->append("首月月供(元)： "+QString::number(fmp,10,0)+"\n");

            double emd = n.every_month_decrease();

            ui->Textout->append("每月递减(元)： "+QString::number(emd,10,0)+"\n");

            double tl = n.total_loan();

            ui->Textout->append("贷款总额(元)： "+QString::number(tl,10,0)+"\n");

            double ip = n.interest_pay();

            ui->Textout->append("支付利息(元)： "+QString::number(ip,10,0)+"\n");

            double tp = n.total_pay();

            ui->Textout->append("还款总额(元)： "+QString::number(tp,10,0)+"\n");

            int mm = n.mortgage_month();

            ui->Textout->append("还款月数(月)： "+QString::number(mm)+"\n");
        }
    }

    ui->Textout->append("感谢您的使用\n");
}

void MainWindow::on_clearbutton_clicked()
{
    QMessageBox::StandardButton btn;

    btn = QMessageBox::question(this, "提示", "确实要删除吗?", QMessageBox::Yes|QMessageBox::No);

    if (btn == QMessageBox::Yes)
    {
        ui->area->setText("0");

        ui->unit_price->setText("0");

        ui->interest_rate1->setText("0");

        ui->mortgage_rate1->setText("0");

        ui->totalloan->setText("0");

        ui->interest_rate2->setText("0");

        ui->buss_loan->setText("0");

        ui->buss_interest_rate->setText("0");

        ui->com_loan->setText("0");

        ui->com_interest_rate->setText("0");

        ui->mortgage_year->setText("1");

        ui->Textout->setText("重置成功！\n");
    }
}
