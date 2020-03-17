#ifndef MAINSUBSUBMODEL_H
#define MAINSUBSUBMODEL_H

#include <QObject>

class MainSubSubModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString subSubData READ subSubData WRITE setSubSubData NOTIFY subSubDataChanged)

public:
    explicit MainSubSubModel(QObject *parent = nullptr);

    QString subSubData() const;
    void setSubSubData(const QString &subSubData);

signals:

    void subSubDataChanged(QString);

public slots:

private:

    QString data_;
};

#endif // MAINSUBSUBMODEL_H
