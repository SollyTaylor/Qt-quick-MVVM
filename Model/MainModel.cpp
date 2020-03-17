#include "MainModel.h"
#include "MainSubModel.h"
#include "MainSubSubModel.h"

#include "ModelNames.h"
#include <iostream>
MainModel::MainModel(QObject *parent)
    : QObject(parent),
    _subModel(new MainSubModel(this)) {
    setObjectName(mainModelStr);

    connect(this->_subModel,
            &MainSubModel::subDataChanged,
            this,
            &MainModel::slot_submodel_changed);

}

QString MainModel::GetSourceValue() const { return _sourceValue; }

void MainModel::SetSourceValue(const QString &value) { _sourceValue = value; }

QString MainModel::GetDestinationValue() const { return _destinationValue; }

void MainModel::SetDestinationValue(const QString &value) {
    if (!value.isEmpty()) {
        _destinationValue = HashValue(value);
    } else {
        _destinationValue = value;
    }
}

QObject *MainModel::subModel() { return _subModel;}

void MainModel::slot_submodel_changed(QString arg)
{
    SetSourceValue(arg);
    this->_subModel->setSubData(arg);
    this->_subModel->getSubSubModel()->setSubSubData(arg);
}

QString MainModel::HashValue(const QString &value) {
    return QString(
                QCryptographicHash::hash(value.toUtf8(), QCryptographicHash::Md5)
                .toHex());
}
