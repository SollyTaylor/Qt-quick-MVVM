#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QCryptographicHash>
#include <QObject>

class MainSubModel;
class MainModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObject* subModel READ subModel NOTIFY subModelChanged)

private:

  QString _sourceValue;
  QString _destinationValue;
  MainSubModel* _subModel;

public:

  explicit MainModel(QObject* parent);
  virtual ~MainModel() {}

  QString GetSourceValue() const;

  void SetSourceValue(const QString &value);

  QString GetDestinationValue() const;

  void SetDestinationValue(const QString &value);
  QObject *subModel();

signals:
  void subModelChanged();

public slots:

    void slot_submodel_changed(QString arg);

private:

  QString HashValue(const QString &value);
};

#endif // MAINMODEL_H
