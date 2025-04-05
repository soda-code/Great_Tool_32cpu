#include "daojishi.h"
#include "ui_daojishi.h"
#include "ui_daojishi.h"

daojishi::daojishi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::daojishi)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/daojishi.ico"));
    TIME = new QTimer(this);
    TIME->setInterval(10);

    QString tr1 = QString::number(0).asprintf("00:00.000");
    ui->lcdNumber->setDigitCount(10);
    ui->lcdNumber->display(tr1);

    connect(TIME,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(key_on()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(key_off()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(key_reload()));
}

daojishi::~daojishi()
{
    delete ui;
}
void daojishi::onTimeOut()
{
    timer_count=timer_count-0.01;
   // QString str = QString::number(timer_count, 'f', 3);
    QString str1 = QString::number(timer_count).asprintf("%2d:%2d.%3d",(int)timer_count/60,(int)timer_count%60,(int)(timer_count*1000)%1000);
    ui->lcdNumber->display(str1);
    if(timer_count<=0.0)
    {

        dateTime= QDateTime::currentDateTime();
        sdateTimer = dateTime.toString("停止时间 yyyy-MM-dd HH:mm:ss.zzz");
        ui->label_3->setText(sdateTimer);
        str1 = QString::number(0).asprintf("00:00.000");
         ui->lcdNumber->display(str1);
        TIME->stop();
    }
}

void daojishi::key_on()
{
    QString str;
    dateTime= QDateTime::currentDateTime();
    sdateTimer = dateTime.toString("开始时间 yyyy-MM-dd HH:mm:ss.zzz");
    ui->label->setText(sdateTimer);
    str = QString::number(0).asprintf("停止时间");
    ui->label_3->setText(str);
    ui->pushButton->setEnabled(false);

    get_tim=ui->comboBox->currentText() ;

    ui->lcdNumber->display(get_tim);
    timer_count=get_tim.toFloat()*60;

    TIME->start();
}
void daojishi::key_off()
{

    ui->pushButton->setEnabled(true);
    TIME->stop();
}
void daojishi::key_reload()
{
    ui->pushButton->setEnabled(true);
    get_tim=ui->comboBox->currentText() ;
    ui->lcdNumber->display(get_tim);
    timer_count=get_tim.toFloat();
    TIME->stop();
}
