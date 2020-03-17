#include "MainSubModel.h"
#include "MainSubSubModel.h"

MainSubModel::MainSubModel(QObject *parent)
    : QObject(parent)
    , subSubModel_(new MainSubSubModel(this))
{

}

QString MainSubModel::subData() const
{
    return data_;
}

void MainSubModel::setSubData(const QString &data)
{
    data_ = data;
}
