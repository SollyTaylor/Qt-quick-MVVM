#include "MainSubSubModel.h"

MainSubSubModel::MainSubSubModel(QObject *parent) : QObject(parent)
{

}

QString MainSubSubModel::subSubData() const
{
    return data_;
}

void MainSubSubModel::setSubSubData(const QString &data)
{
    data_ = data;
}
