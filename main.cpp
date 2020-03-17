#include "ViewModel/MainViewModel.h"
#include "qmlapplicationviewer.h"
#include <QApplication>
#include <QQmlContext>
#include "ModelNames.h"
int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QmlApplicationViewer viewer;

  MainModel* mainModel = new MainModel(&app);

  viewer.rootContext()->setContextProperty("model",
                                           new MainViewModel(mainModel));

  viewer.setMainQmlFile(QUrl("qrc:/qml/qml/QtQuickMvvmExample/MainView.qml"));
  viewer.showExpanded();

  return app.exec();
}
