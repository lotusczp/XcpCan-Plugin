#ifndef LXCPCANTOOLWIDGET_H
#define LXCPCANTOOLWIDGET_H

#include <QWidget>
#include "LElfVarEditorWidget.h"

namespace Ui {
class LXcpCanToolWidget;
}

class LXcpCanToolWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LXcpCanToolWidget(QWidget *parent = nullptr);
    ~LXcpCanToolWidget();

    LElfVarEditorWidget* getElfVarEditorWidget();

private:
    Ui::LXcpCanToolWidget *ui;
};

#endif // LXCPCANTOOLWIDGET_H
