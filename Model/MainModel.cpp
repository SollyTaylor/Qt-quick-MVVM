#include "MainModel.h"
#include "MainSubModel.h"
#include "MainSubSubModel.h"

#include "ModelNames.h"
#include <iostream>
MainModel::MainModel(QObject *parent)
    : QObject(parent),
    _subModel(new MainSubModel(this, this)) {
    setObjectName(mainModelStr);

    connect(this,
            &MainModel::dataChanged,
            this,
            &MainModel::slotDataChanged);

}

QString MainModel::getData() const {
    return data;
}

void MainModel::setData(const QString &d) {
    if (data != d) {
        data = d;
        emit dataChanged(d);
    }
}

QString MainModel::getEncrypted() const {
    return encrypted;
}

void MainModel::setEncrypted(const QString &value) {
    if (!value.isEmpty()) {
        encrypted = HashValue(value);
    } else {
        encrypted = value;
    }
    emit encryptedChanged(encrypted);
}

QObject *MainModel::subModel() { return _subModel;}

void MainModel::clearCommand()
{
    setEncrypted("");
    setData("");
}

void MainModel::slotDataChanged(QString arg)
{
    this->_subModel->setSubData(arg);
    this->_subModel->getSubSubModel()->setSubSubData(arg);
    setEncrypted(arg);
}


QString MainModel::HashValue(const QString &value) {
    return QString(QCryptographicHash::hash(value.toUtf8(), QCryptographicHash::Md5).toHex());
}
