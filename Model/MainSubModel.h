#ifndef MAINSUBMODEL_H
#define MAINSUBMODEL_H

#include <QObject>

class MainSubSubModel;
class MainSubModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString subData READ subData WRITE setSubData NOTIFY subDataChanged)

public:
    explicit MainSubModel(QObject *parent = nullptr);

    QString subData() const;
    void setSubData(const QString &subData);

signals:

    void subDataChanged();

public slots:

private:

    QString data_;
    MainSubSubModel* subSubModel_;
};

#endif // MAINSUBMODEL_H
