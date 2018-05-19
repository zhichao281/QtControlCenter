#include "KeyBoard.h"
#include "ui_keyboard.h"
#include <QDebug>

KeyBoard::KeyBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyBoard)
{
    ui->setupUi(this);
    //    setWindowFlags(Qt::Tool|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    ui->display->setFocus();
    button_init();

    waitingForOperand = true;
    inputMode = iMode_Normal;
    caps_Lock = false;

    signalMapper=new QSignalMapper(this);
    setMapper();//调用了setMapper函数，英文字母数字键盘集群关联信号和漕
    connectMapper();
    connect(signalMapper,SIGNAL(mapped(const QString&)),
            this,SLOT(setDispText(const QString&)));
    connect(ui->toolButton_enter,SIGNAL(clicked()),this,SLOT(onEnter()));
    connect(ui->toolButton_backspace,SIGNAL(clicked()),this,SLOT(onBackspace()));

    connect(ui->toolButton_up,SIGNAL(clicked()),this,SLOT(onCursorUp()));
    connect(ui->toolButton_down,SIGNAL(clicked()),this,SLOT(onCursorDown()));
    connect(ui->toolButton_right,SIGNAL(clicked()),this,SLOT(onCursorRight()));
    connect(ui->toolButton_left,SIGNAL(clicked()),this,SLOT(onCursorLeft()));
    connect(ui->toolButton_inv,SIGNAL(clicked()),this,SLOT(onInvMode()));
    connect(ui->toolButton_capslock,SIGNAL(clicked()),this,SLOT(onCapslock()));
}

KeyBoard::~KeyBoard()
{
    delete ui;
}
void KeyBoard::button_init()
{
    ui->display->setStyleSheet("QLineEdit{font-size:25px;color:rgb(0,0,0);"
                               "height:50px;border:2px solid rgb(155,200,33);"
                               "border-radius:10px;}");
    ui->toolButton_0->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_1->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_2->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_3->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_4->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                    " background-color:gray;color:white;font-size:25px");
    ui->toolButton_5->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_6->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_7->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_8->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                    " background-color:gray;color:white;font-size:25px");
    ui->toolButton_9->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_backspace->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                            " background-color:gray;color:white;font-size:25px");
    ui->toolButton_enter->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                        "background-color:gray;color:white;font-size:25px}");

    ui->toolButton_a->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_b->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_c->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_d->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_e->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                    " background-color:gray;color:white;font-size:25px");
    ui->toolButton_f->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_g->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_h->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_8->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                    " background-color:gray;color:white;font-size:25px");
    ui->toolButton_i->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");

    ui->toolButton_j->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_k->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_l->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_m->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_n->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                    " background-color:gray;color:white;font-size:25px");
    ui->toolButton_o->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_p->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_q->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_r->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                    " background-color:gray;color:white;font-size:25px");
    ui->toolButton_s->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");

    ui->toolButton_t->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_u->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_v->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_w->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_x->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                    " background-color:gray;color:white;font-size:25px");
    ui->toolButton_y->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_z->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                    "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_wenhao->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                         "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_xinghao->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                          " background-color:gray;color:white;font-size:25px");
    ui->toolButton_up->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                     "background-color:gray;color:white;font-size:25px}");

    ui->toolButton_down->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                       "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_left->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                       "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_right->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                        "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_tab->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                      "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_esc->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                      " background-color:gray;color:white;font-size:25px");
    ui->toolButton_line1->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                        "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_line2->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                        "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_line3->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                        "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_dot->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                      "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_capslock->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                           "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_space->setStyleSheet("border:2px groove gray;border-radius:10px;"
                                        " background-color:gray;color:white;font-size:25px");
    ui->toolButton_fenhao->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                         "background-color:gray;color:white;font-size:25px}");
    ui->toolButton_inv->setStyleSheet("QToolButton{border:2px groove white;border-radius:10px;"
                                      "background-color:gray;color:white;font-size:25px}");

    //    QPalette   pal;//字体颜色的修改
    //    pal.setColor(QPalette::ButtonText,QColor(0,0,0));
    //    ui->toolButton_0->setPalette(pal);

}

void KeyBoard::setMapper()
{
    //number
    signalMapper->setMapping(ui->toolButton_0,ui->toolButton_0->text());
    signalMapper->setMapping(ui->toolButton_1,ui->toolButton_1->text());
    signalMapper->setMapping(ui->toolButton_2,ui->toolButton_2->text());
    signalMapper->setMapping(ui->toolButton_3,ui->toolButton_3->text());
    signalMapper->setMapping(ui->toolButton_4,ui->toolButton_4->text());
    signalMapper->setMapping(ui->toolButton_5,ui->toolButton_5->text());
    signalMapper->setMapping(ui->toolButton_6,ui->toolButton_6->text());
    signalMapper->setMapping(ui->toolButton_7,ui->toolButton_7->text());
    signalMapper->setMapping(ui->toolButton_8,ui->toolButton_8->text());
    signalMapper->setMapping(ui->toolButton_9,ui->toolButton_9->text());
    //letter
    signalMapper->setMapping(ui->toolButton_a,ui->toolButton_a->text());
    signalMapper->setMapping(ui->toolButton_b,ui->toolButton_b->text());
    signalMapper->setMapping(ui->toolButton_c,ui->toolButton_c->text());
    signalMapper->setMapping(ui->toolButton_d,ui->toolButton_d->text());
    signalMapper->setMapping(ui->toolButton_e,ui->toolButton_e->text());
    signalMapper->setMapping(ui->toolButton_f,ui->toolButton_f->text());
    signalMapper->setMapping(ui->toolButton_g,ui->toolButton_g->text());
    signalMapper->setMapping(ui->toolButton_h,ui->toolButton_h->text());
    signalMapper->setMapping(ui->toolButton_i,ui->toolButton_i->text());
    signalMapper->setMapping(ui->toolButton_j,ui->toolButton_j->text());
    signalMapper->setMapping(ui->toolButton_k,ui->toolButton_k->text());
    signalMapper->setMapping(ui->toolButton_l,ui->toolButton_l->text());
    signalMapper->setMapping(ui->toolButton_m,ui->toolButton_m->text());
    signalMapper->setMapping(ui->toolButton_n,ui->toolButton_n->text());
    signalMapper->setMapping(ui->toolButton_o,ui->toolButton_o->text());
    signalMapper->setMapping(ui->toolButton_p,ui->toolButton_p->text());
    signalMapper->setMapping(ui->toolButton_q,ui->toolButton_q->text());
    signalMapper->setMapping(ui->toolButton_r,ui->toolButton_r->text());
    signalMapper->setMapping(ui->toolButton_s,ui->toolButton_s->text());
    signalMapper->setMapping(ui->toolButton_t,ui->toolButton_t->text());
    signalMapper->setMapping(ui->toolButton_u,ui->toolButton_u->text());
    signalMapper->setMapping(ui->toolButton_v,ui->toolButton_v->text());
    signalMapper->setMapping(ui->toolButton_w,ui->toolButton_w->text());
    signalMapper->setMapping(ui->toolButton_x,ui->toolButton_x->text());
    signalMapper->setMapping(ui->toolButton_y,ui->toolButton_y->text());
    signalMapper->setMapping(ui->toolButton_z,ui->toolButton_z->text());

    //other
    signalMapper->setMapping(ui->toolButton_line1,ui->toolButton_line1->text());
    signalMapper->setMapping(ui->toolButton_line2,ui->toolButton_line2->text());
    signalMapper->setMapping(ui->toolButton_line3,ui->toolButton_line3->text());
    signalMapper->setMapping(ui->toolButton_wenhao,ui->toolButton_wenhao->text());
    signalMapper->setMapping(ui->toolButton_dot,ui->toolButton_dot->text());
    signalMapper->setMapping(ui->toolButton_fenhao,ui->toolButton_fenhao->text());
    signalMapper->setMapping(ui->toolButton_xinghao,ui->toolButton_xinghao->text());
    signalMapper->setMapping(ui->toolButton_space," ");
    signalMapper->setMapping(ui->toolButton_tab,"\t");
}

void KeyBoard::connectMapper()
{
    connect(ui->toolButton_0,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_1,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_2,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_3,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_4,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_5,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_6,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_7,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_8,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_9,SIGNAL(clicked()),signalMapper,SLOT(map()));
    //letter
    connect(ui->toolButton_a,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_b,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_c,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_d,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_e,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_f,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_g,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_h,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_i,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_j,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_k,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_l,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_m,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_n,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_o,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_p,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_q,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_r,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_s,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_t,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_u,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_v,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_w,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_x,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_y,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_z,SIGNAL(clicked()),signalMapper,SLOT(map()));
    //other
    connect(ui->toolButton_line1,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_line2,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_line3,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_wenhao,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_dot,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_space,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_tab,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_fenhao,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(ui->toolButton_xinghao,SIGNAL(clicked()),signalMapper,SLOT(map()));

}

void KeyBoard::setDispText(const QString &text)
{
    if(waitingForOperand)
    {
        ui->display->clear();
        waitingForOperand = false;
    }
    ui->display->insert(text);
}

void KeyBoard::onEnter()
{
    waitingForOperand = true;
    text = ui->display->text();
    qDebug()<<"input"<<text;
    emit setvalue(text);
    ui->display->clear();
    this->close();
    //qDebug() << text << endl;

}

void KeyBoard::onBackspace()
{
    ui->display->backspace();
}
/*支持鼠标拖拽键盘*/
void KeyBoard::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
    {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}

void KeyBoard::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    if (event->button() == Qt::RightButton)
    {
        close();
    }
}
/*************************************************************/
void KeyBoard::onCursorUp()
{
    QKeyEvent upPress(QEvent::KeyPress,Qt::Key_Up,Qt::NoModifier);//还可以这样做
    QApplication::sendEvent(QApplication::focusWidget(),&upPress);
}

void KeyBoard::onCursorDown()
{
    QKeyEvent downPress(QEvent::KeyPress,Qt::Key_Down,Qt::NoModifier);
    QApplication::sendEvent(QApplication::focusWidget(),&downPress);
}

/*
* Name : void onCursorRight()
* Type : slot
* Func : cursor move right
* In   : Null
* Out  : Null
*/
void KeyBoard::onCursorRight()
{
    ui->display->cursorForward(false,1);
}

/*
* Name : void onCursorLeft()
* Type : slot
* Func : cursor move left
* In   : Null
* Out  : Null
*/
void KeyBoard::onCursorLeft()
{
    ui->display->cursorBackward(false,1);
}

void KeyBoard::onCapslock()
{
    caps_Lock = !caps_Lock;
    if(caps_Lock)
    {
        //letter
        ui->toolButton_a->setText("A");
        ui->toolButton_b->setText("B");
        ui->toolButton_c->setText("C");
        ui->toolButton_d->setText("D");
        ui->toolButton_e->setText("E");
        ui->toolButton_f->setText("F");
        ui->toolButton_g->setText("G");
        ui->toolButton_h->setText("H");
        ui->toolButton_i->setText("I");
        ui->toolButton_j->setText("J");
        ui->toolButton_k->setText("K");
        ui->toolButton_l->setText("L");
        ui->toolButton_m->setText("M");
        ui->toolButton_n->setText("N");
        ui->toolButton_o->setText("O");
        ui->toolButton_p->setText("P");
        ui->toolButton_q->setText("Q");
        ui->toolButton_r->setText("R");
        ui->toolButton_s->setText("S");
        ui->toolButton_t->setText("T");
        ui->toolButton_u->setText("U");
        ui->toolButton_v->setText("V");
        ui->toolButton_w->setText("W");
        ui->toolButton_x->setText("X");
        ui->toolButton_y->setText("Y");
        ui->toolButton_z->setText("Z");
//        toolButton_line1->setText("<");
//        toolButton_line2->setText(">");
//        toolButton_line3->setText("-");
//        toolButton_dot->setText("*");
//        toolButton_wenhao->setText("#");
    }
    else
    {
        //letter
        ui->toolButton_a->setText("a");
        ui->toolButton_b->setText("b");
        ui->toolButton_c->setText("c");
        ui->toolButton_d->setText("d");
        ui->toolButton_e->setText("e");
        ui->toolButton_f->setText("f");
        ui->toolButton_g->setText("g");
        ui->toolButton_h->setText("h");
        ui->toolButton_i->setText("i");
        ui->toolButton_j->setText("j");
        ui->toolButton_k->setText("k");
        ui->toolButton_l->setText("l");
        ui->toolButton_m->setText("m");
        ui->toolButton_n->setText("n");
        ui->toolButton_o->setText("o");
        ui->toolButton_p->setText("p");
        ui->toolButton_q->setText("q");
        ui->toolButton_r->setText("r");
        ui->toolButton_s->setText("s");
        ui->toolButton_t->setText("t");
        ui->toolButton_u->setText("u");
        ui->toolButton_v->setText("v");
        ui->toolButton_w->setText("w");
        ui->toolButton_x->setText("x");
        ui->toolButton_y->setText("y");
        ui->toolButton_z->setText("z");
//        toolButton_line1->setText("/");
//        toolButton_line2->setText("\\");
//        toolButton_line3->setText("_");
//        toolButton_dot->setText(".");
//        toolButton_wenhao->setText("?");
    }
    setMapper();
}

void KeyBoard::onInvMode()
{
    if(inputMode == iMode_Normal)
    {
        inputMode = iMode_Passwd;
    }
    else if(inputMode == iMode_Passwd)
    {
        inputMode = iMode_Normal;
    }

    if(inputMode == iMode_Normal)
    {
        ui->display->setEchoMode(QLineEdit::Normal);
    }
    else if(inputMode == iMode_Passwd)
    {
        ui->display->setEchoMode(QLineEdit::Password);
    }
}
