#include "mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QMainWindow>
#include <QString>
#include <QStringList>

using namespace Qt::Literals::StringLiterals;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("QtProject"_L1);
    QCoreApplication::setApplicationName("DocumentViewer"_L1);
    QCoreApplication::setApplicationVersion("1.0"_L1);

    QCommandLineParser parser;
    parser.setApplicationDescription(QApplication::translate("main", "A viewer for JSON, PDF and text files"));
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("File"_L1, QApplication::translate("main", "JSON, PDF or text file to open"));
    parser.process(app);

    const QStringList &positionalArguments = parser.positionalArguments();
    const QString &fileName = (positionalArguments.count() > 0) ? positionalArguments.at(0)
                                                                : QString();

    MainWindow w;
    w.show();
    if (!fileName.isEmpty())
        w.openFile(fileName);

    return app.exec();
}

