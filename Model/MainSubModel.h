#ifndef MAINSUBMODEL_H
#define MAINSUBMODEL_H

#include <QObject>

class MainModel;
class MainSubSubModel;
class MainSubModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString subData READ subData WRITE setSubData NOTIFY subDataChanged)
    Q_PROPERTY(QObject *subsubModel READ subsubModel NOTIFY subsubModelChanged)
public:
    explicit MainSubModel(MainModel* mainModel, QObject *parent = nullptr);

    QString subData() const;
    void setSubData(const QString &subData);

    QObject *subsubModel();
    MainSubSubModel* getSubSubModel();
    MainModel *getMainModel() const;

signals:

    void subDataChanged(QString);
    void subsubModelChanged();

public slots:

    void slotSubDataChanged(QString arg);

private:

    QString data_;
    MainModel* mainModel_;
    MainSubSubModel* subSubModel_;

};

#endif // MAINSUBMODEL_H
