#include "MainSubModel.h"
#include "MainSubSubModel.h"
#include "ModelNames.h"
MainSubModel::MainSubModel(QObject *parent)
    : QObject(parent)
    , subSubModel_(new MainSubSubModel(this))
{
    setObjectName(mainSubModelStr);
}

QString MainSubModel::subData() const
{
    return data_;
}

void MainSubModel::setSubData(const QString &data)
{
    data_ = data;
}

QObject *MainSubModel::subsubModel()
{
    return subSubModel_;
}
