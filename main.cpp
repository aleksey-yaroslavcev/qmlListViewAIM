#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "TestModel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    TestModel model;

    QQmlApplicationEngine engine;
    QQmlContext* rootContext = engine.rootContext();

    rootContext->setContextProperty("testModel", &model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
