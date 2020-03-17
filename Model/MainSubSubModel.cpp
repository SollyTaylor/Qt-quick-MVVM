#include "MainSubSubModel.h"
#include "ModelNames.h"
#include "MainModel.h"
#include "MainSubModel.h"
MainSubSubModel::MainSubSubModel(MainSubModel* subModel, QObject *parent)
    : QObject(parent)
    , subModel_(subModel)
{
    setObjectName(mainSubSubModelStr);
    connect(this,
            &MainSubSubModel::subSubDataChanged,
            this,
            &MainSubSubModel::slotSubSubDataChanged);
}

QString MainSubSubModel::subSubData() const
{
    return data_;
}

void MainSubSubModel::setSubSubData(const QString &data)
{
    if (data != data_) {
        data_ = data;
        emit subSubDataChanged(data);
    }
}

void MainSubSubModel::slotSubSubDataChanged(QString arg)
{
    this->subModel_->setSubData(arg);
    this->subModel_->getMainModel()->setData(arg);
}
