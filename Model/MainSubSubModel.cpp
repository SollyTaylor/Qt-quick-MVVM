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
    if (data != data_) {
        data_ = data;
        emit subSubDataChanged(data);
    }
}
