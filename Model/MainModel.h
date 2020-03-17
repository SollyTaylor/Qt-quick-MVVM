#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QCryptographicHash>
#include <QObject>

class MainSubModel;
class MainModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString data READ getData WRITE setData NOTIFY dataChanged)
    Q_PROPERTY (QString encrypted READ getEncrypted WRITE setEncrypted NOTIFY encryptedChanged)

    Q_PROPERTY(QObject* subModel READ subModel NOTIFY subModelChanged)

private:

    QString data;
    QString encrypted;
    MainSubModel* _subModel;

public:

    explicit MainModel(QObject* parent);
    virtual ~MainModel() {}

    QString getData() const;

    void setData(const QString &value);

    QString getEncrypted() const;

    void setEncrypted(const QString &value);
    QObject *subModel();

    Q_INVOKABLE void clearCommand();

signals:

    void encryptedChanged(QString);
    void dataChanged(QString);
    void subModelChanged();

public slots:

    void slotDataChanged(QString arg);

private:

    QString HashValue(const QString &value);
};

#endif // MAINMODEL_H
