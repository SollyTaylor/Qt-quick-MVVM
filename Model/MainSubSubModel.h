#ifndef MAINSUBSUBMODEL_H
#define MAINSUBSUBMODEL_H

#include <QObject>

class MainModel;
class MainSubModel;
class MainSubSubModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString subSubData READ subSubData WRITE setSubSubData NOTIFY subSubDataChanged)

public:
    explicit MainSubSubModel(MainSubModel* subModel, QObject *parent = nullptr);

    QString subSubData() const;
    void setSubSubData(const QString &subSubData);

signals:

    void subSubDataChanged(QString);

public slots:

    void slotSubSubDataChanged(QString arg);

private:

    QString data_;
    MainSubModel* subModel_;
};

#endif // MAINSUBSUBMODEL_H
