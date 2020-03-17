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
    return _mainModel->GetSourceValue();
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
    return _mainModel->GetDestinationValue();
}

QObject *MainViewModel::mainModel() {
    return _mainModel;
}

void MainViewModel::SetSourceValue(QString &arg)
{
    if (_mainModel->GetSourceValue() != arg) {
        _mainModel->SetSourceValue(arg);
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
    if (_mainModel->GetDestinationValue() != arg) {
        _mainModel->SetDestinationValue(arg);
        DestinationChangedEvent(arg);
    }

}
