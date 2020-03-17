#include "MainSubModel.h"
#include "MainSubSubModel.h"
#include "ModelNames.h"
MainSubModel::MainSubModel(QObject *parent)
    : QObject(parent)
    , subSubModel_(new MainSubSubModel(this))
{
    setObjectName(mainSubModelStr);
    connect(subSubModel_,
            &MainSubSubModel::subSubDataChanged,
            this,
            &MainSubModel::slot_update_subsubmodel);
}

QString MainSubModel::subData() const
{
    return data_;
}

void MainSubModel::setSubData(const QString &data)
{
    if (data != data_) {
        data_ = data;
        emit subDataChanged(data_);
    }
}

QObject *MainSubModel::subsubModel()
{
    return subSubModel_;
}

MainSubSubModel *MainSubModel::getSubSubModel()
{
    return this->subSubModel_;
}

void MainSubModel::slot_update_subsubmodel(QString arg)
{
    setSubData(arg);
    this->subSubModel_->setSubSubData(arg);
}
