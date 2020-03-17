#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include "../Model/MainModel.h"

class MainViewModel : public QObject
{
    Q_OBJECT

private:
    // main model
    MainModel* _mainModel;

    // declaration of source property
    Q_PROPERTY (QString sourceValue READ GetSourceValue WRITE SetSourceValue NOTIFY SourceChangedEvent)

    // declaration of destination property
    Q_PROPERTY (QString destinationValue READ GetDestinationValue WRITE SetDestinationValue
                NOTIFY DestinationChangedEvent)

public:
    explicit MainViewModel(MainModel* mainModel);

    virtual ~MainViewModel();

    Q_INVOKABLE void clearCommand();

    QString GetSourceValue() const;

    QString GetDestinationValue() const;

public slots:
    void SetSourceValue(QString& arg);

    void SetDestinationValue(QString& arg);

signals:
    void SourceChangedEvent(QString& arg);
    void DestinationChangedEvent(QString& arg);
};

#endif // MAINVIEWMODEL_H
