#include "MainViewModel.h"

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
    }
}

void MainViewModel::SetDestinationValue(QString &arg)
{
    if (_mainModel->GetDestinationValue() != arg) {
        _mainModel->SetDestinationValue(arg);
        DestinationChangedEvent(arg);
    }
}
