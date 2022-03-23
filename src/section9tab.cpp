#include "section9tab.h"
#include "ui_section9tab.h"

Section9Tab::Section9Tab(SaveManager* mgr, QWidget* parent, int sectionId)
    : Tab(mgr, parent, sectionId)
    , ui(new Ui::Section9Tab)
{
    ui->setupUi(this);
    connect(ui->resetButton, SIGNAL(clicked(bool)), SLOT(update()));
    connect(ui->applyButton, SIGNAL(clicked(bool)), SLOT(apply()));
}

Section9Tab::~Section9Tab()
{
    delete ui;
}

void Section9Tab::update()
{
    quint32 money = this->read<quint32>(0x0);
    quint32 jewel = this->read<quint32>(0xC);
    ui->moneyCB->setValue(money);
    ui->jewelCB->setValue(jewel);
    ui->applyButton->setEnabled(true);
    ui->resetButton->setEnabled(true);
}

void Section9Tab::apply()
{
    this->write<quint32>(ui->moneyCB->value(), 0x00); // money
    this->write<quint32>(ui->jewelCB->value(), 0x0C); // jewel
}
