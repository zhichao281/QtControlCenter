#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QSignalMapper>
#include <QMouseEvent>

namespace Ui {
class KeyBoard;
}

class KeyBoard : public QWidget
{
    Q_OBJECT
public:
    explicit KeyBoard(QWidget *parent = 0);
    ~KeyBoard();
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    enum
    {
        iMode_Normal = 0,
        iMode_Passwd = 1
    }; //密码模式与正常模式
private:
    Ui::KeyBoard *ui;
    int inputMode;
    bool waitingForOperand;
    QSignalMapper *signalMapper;
    QPoint dragPosition;
    bool caps_Lock;


private:
    void setMapper();
    void connectMapper();
    void button_init();

public:
    QString text;
signals:
    void setvalue(QString text);
private slots:
    void setDispText(const QString& text);
    void onEnter();
    void onBackspace();

    /*方向光标移动*/
    void onCursorRight();
    void onCursorLeft();
    void onCursorUp();
    void onCursorDown();
    /*******大小写*/
    void onInvMode();
    void onCapslock();

};

#endif // KEYBOARD_H