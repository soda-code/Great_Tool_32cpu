#ifndef DAOJISHI_H
#define DAOJISHI_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui {
class daojishi;
}
QT_END_NAMESPACE

class daojishi : public QMainWindow
{
    Q_OBJECT

    public:
        daojishi(QWidget *parent = nullptr);
        ~daojishi();

    private:
        Ui::daojishi *ui;
        QTimer *TIME;
        QString sdateTimer;
        QString get_tim;
        float timer_count;

        QDateTime dateTime;
    public slots:
        void onTimeOut();
        void key_on();
        void key_off();
        void key_reload();
};
#endif // DAOJISHI_H
