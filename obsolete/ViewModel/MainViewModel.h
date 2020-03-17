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

    Q_PROPERTY(QString subData READ GetSubData WRITE SetSubData NOTIFY SubDataChanged)
    Q_PROPERTY(QString subSubData READ GetSubSubData WRITE SetSubSubData NOTIFY SubSubDataChanged)


    // declaration of destination property
    Q_PROPERTY (QString destinationValue READ GetDestinationValue WRITE SetDestinationValue
                NOTIFY DestinationChangedEvent)

    Q_PROPERTY(QObject *mainModel READ mainModel NOTIFY mainModelChanged)
public:

    explicit MainViewModel(MainModel* mainModel);

    virtual ~MainViewModel();

    Q_INVOKABLE void clearCommand();

    QString GetSourceValue() const;
    QString GetSubData() const;
    QString GetSubSubData() const;

    QString GetDestinationValue() const;

    QObject *mainModel();

public slots:

    void SetSourceValue(QString& arg);
    void SetSubData(QString& arg);
    void SetSubSubData(QString& arg);
    void SetDestinationValue(QString& arg);

signals:
    void SourceChangedEvent(QString& arg);
    void SubDataChanged(QString& arg);
    void SubSubDataChanged(QString& arg);
    void DestinationChangedEvent(QString& arg);
    void mainModelChanged();
};

#endif // MAINVIEWMODEL_H
