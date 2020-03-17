#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QCryptographicHash>
#include <QObject>

class MainSubModel;
class MainModel : public QObject {
    Q_OBJECT
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

private:

  QString HashValue(const QString &value);
};

#endif // MAINMODEL_H
