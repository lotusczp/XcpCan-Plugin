#include "LXcpCanToolWidget.h"
#include "ui_LXcpCanToolWidget.h"

LXcpCanToolWidget::LXcpCanToolWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LXcpCanToolWidget)
{
    ui->setupUi(this);
}

LXcpCanToolWidget::~LXcpCanToolWidget()
{
    delete ui;
}

LElfVarEditorWidget *LXcpCanToolWidget::getElfVarEditorWidget()
{
    return ui->widget;
}
