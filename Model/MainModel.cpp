#include "MainModel.h"
#include "MainSubModel.h"
#include "ModelNames.h"
MainModel::MainModel(QObject *parent)
    : QObject(parent), _subModel(new MainSubModel(this)) {
    setObjectName(mainModelStr);
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

QString MainModel::HashValue(const QString &value) {
    return QString(
                QCryptographicHash::hash(value.toUtf8(), QCryptographicHash::Md5)
                .toHex());
}
