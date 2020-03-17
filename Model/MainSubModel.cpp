#include "MainSubModel.h"
#include "MainSubSubModel.h"
#include "MainModel.h"
#include "ModelNames.h"
MainSubModel::MainSubModel(MainModel* mainModel, QObject *parent)
    : QObject(parent)
    , mainModel_(mainModel)
    , subSubModel_(new MainSubSubModel(this, this))
{
    setObjectName(mainSubModelStr);
    connect(this,
            &MainSubModel::subDataChanged,
            this,
            &MainSubModel::slotSubDataChanged);
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

void MainSubModel::slotSubDataChanged(QString arg)
{
    this->mainModel_->setData(arg);
    this->subSubModel_->setSubSubData(arg);
}

MainModel *MainSubModel::getMainModel() const
{
    return mainModel_;
}
