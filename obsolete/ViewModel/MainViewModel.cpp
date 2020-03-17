#include "MainViewModel.h"
#include "MainSubModel.h"

MainViewModel::MainViewModel(MainModel *mainModel)
{
    _mainModel = mainModel;
}

MainViewModel::~MainViewModel()
{ }

void MainViewModel::clearCommand() // clear command
{
    QString emptyString = "";
    SetSourceValue(emptyString);
}

QString MainViewModel::GetSourceValue() const
{
    return _mainModel->getData();
}

QString MainViewModel::GetSubData() const
{
    return QString();
}

QString MainViewModel::GetSubSubData() const
{
    return QString();
}

QString MainViewModel::GetDestinationValue() const
{
    return _mainModel->getEncrypted();
}

QObject *MainViewModel::mainModel() {
    return _mainModel;
}

void MainViewModel::SetSourceValue(QString &arg)
{
    if (_mainModel->getData() != arg) {
        _mainModel->setData(arg);
        SourceChangedEvent(arg);
        SetDestinationValue(arg);

        auto submodel = static_cast<MainSubModel*>(_mainModel->subModel());
        submodel->setSubData(arg);
    }
}

void MainViewModel::SetSubData(QString &arg)
{
    auto submodel = static_cast<MainSubModel*>(_mainModel->subModel());
    if (submodel->subData() != arg) {

    }
}

void MainViewModel::SetSubSubData(QString &arg)
{

}

void MainViewModel::SetDestinationValue(QString &arg)
{
    if (_mainModel->getEncrypted() != arg) {
        _mainModel->setEncrypted(arg);
        DestinationChangedEvent(arg);
    }

}
