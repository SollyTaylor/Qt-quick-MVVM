#include "MainSubSubModel.h"
#include "ModelNames.h"
MainSubSubModel::MainSubSubModel(QObject *parent) : QObject(parent)
{
    setObjectName(mainSubSubModelStr);
}

QString MainSubSubModel::subSubData() const
{
    return data_;
}

void MainSubSubModel::setSubSubData(const QString &data)
{
    data_ = data;
}
