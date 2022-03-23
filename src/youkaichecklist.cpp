#include "youkaichecklist.h"

YoukaiCheckList::YoukaiCheckList(int sectionId, int offset, SaveManager* mgr, QWidget* parent)
    : QListWidget(parent)
    , sectionId(sectionId)
    , offset(offset)
    , mgr(mgr)
{
    /* intert items into list */
    foreach (const dataentry_t& it, GameData::getInstance().getData("youkaiNum")) {
        quint32 index = it.first;
        QListWidgetItem* ia = new QListWidgetItem(QString("%1 %2").arg(index, 3, 10, QChar('0')).arg(it.second.value("name")), this);
        ia->setFlags(ia->flags() | Qt::ItemIsUserCheckable);
        ia->setCheckState(Qt::Unchecked);
    }
}

void YoukaiCheckList::update()
{
    QVector<bool> vb = this->mgr->readBoolVector(this->offset, this->count() + 1, this->sectionId); // include 0th element
    for (int i = 0; i < this->count(); ++i) {
        if (vb.at(i + 1)) {
            this->item(i)->setCheckState(Qt::Checked);
        } else {
            this->item(i)->setCheckState(Qt::Unchecked);
        }
    }
}

void YoukaiCheckList::apply()
{
    QVector<bool> vb;
    vb.append(false);
    for (int i = 0; i < this->count(); ++i) {
        if (this->item(i)->checkState() == Qt::Checked) {
            vb.append(true);
        } else {
            vb.append(false);
        }
    }
    this->mgr->writeBoolVector(vb, this->offset, this->sectionId);
}

void YoukaiCheckList::setAllState(bool isChecked)
{
    if (isChecked) {
        for (int i = 0; i < this->count(); ++i) {
            this->item(i)->setCheckState(Qt::Checked);
        }
    } else {
        for (int i = 0; i < this->count(); ++i) {
            this->item(i)->setCheckState(Qt::Unchecked);
        }
    }
}

void YoukaiCheckList::setAllChecked()
{
    this->setAllState(true);
}

void YoukaiCheckList::setAllUnchecked()
{
    this->setAllState(false);
}
