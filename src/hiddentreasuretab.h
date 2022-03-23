#ifndef HIDDEN_TREASURE_TAB_H
#define HIDDEN_TREASURE_TAB_H

#include <QCheckBox>
#include <QWidget>
#include <QtCore>

#include "gameconfig.h"
#include "gamedata.h"
#include "listtab.h"

#include "ui_hiddentreasuretabform.h"

class HiddenTreasureTab : public ListTab, private Ui::HiddenTreasureTabForm {
    Q_OBJECT

public:
    explicit HiddenTreasureTab(SaveManager* mgr, QWidget* parent = 0, int sectionId = -1);
    ~HiddenTreasureTab();

private:
    Ui::HiddenTreasureTabForm* form;
};

#endif // HIDDEN_TREASURE_TAB_H
