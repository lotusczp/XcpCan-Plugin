#ifndef LXCPCANSETTINGSRELIER_H
#define LXCPCANSETTINGSRELIER_H

#include <QObject>
#include "LSettingsRelier.h"
#include "LElfVarEditorWidget.h"

class LXcpCanSettingsRelier : public QObject, public LSettingsRelier
{
    Q_OBJECT
public:
    LXcpCanSettingsRelier(LXcpCanDataMap &a_rAllDataMap, LElfVarEditorWidget* a_pElfVarEditorWidget);
    virtual ~LXcpCanSettingsRelier() {}

    void parseFromSetting(LObixTreeIter a_obixIter) Q_DECL_OVERRIDE ;

    void convertToSetting() Q_DECL_OVERRIDE ;

public slots:
    void saveSettings();

private:
    LElfVarEditorWidget *m_pElfVarEditorWidget;
    LXcpCanDataMap         &m_rAllDataMap;
};

#endif // LXCPCANSETTINGSRELIER_H
