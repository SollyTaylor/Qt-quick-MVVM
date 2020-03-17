
#include <QApplication>
#include <QQmlContext>
#include <QFont>

#include "MainModel.h"
#include "qmlapplicationviewer.h"
#include "ModelNames.h"


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QmlApplicationViewer viewer;

  QFont font("Courier New");
  font.setStyleHint(QFont::Monospace);
  QApplication::setFont(font);

//  MainModel* mainModel = new MainModel(&app);

  viewer.rootContext()->setContextProperty("mainModel",
                                           new MainModel(&app));

  viewer.setMainQmlFile(QUrl("qrc:/qml/qml/QtQuickMvvmExample/MainView.qml"));
  viewer.showExpanded();

  return app.exec();
}
