#include "QtWidgetsApplication1.h"
#include <QInputDialog>
#include <QDir>
#include <QMessageBox>

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowTitle("Full Stack Web App Generator");
    connect(ui.actionProject_3, &QAction::triggered, this, &QtWidgetsApplication1::on_actionProject_3_triggered);
}



QtWidgetsApplication1::~QtWidgetsApplication1() {}

void QtWidgetsApplication1::on_actionProject_3_triggered() {
    qDebug() << "Project Name dialog opened";
    bool ok;
    QString projectName = QInputDialog::getText(this, "Enter Project Name", "Project Name:", QLineEdit::Normal, "", &ok);

    if (ok && !projectName.isEmpty()) {
        // Step 2: Create the base directory
        QString basePath = "C:\\Users\\XC\\OneDrive\\Documents\\Full Stack App Generator CProject";
        QString fullPath = basePath + "\\" + projectName;

        QDir dir(fullPath);

        // Step 3: Check if the base directory already exists
        if (dir.exists()) {
            QMessageBox::warning(this, "Error", "A project with that name already exists!");
            return;
        }

        // Step 4: Create the directory structure
        if (dir.mkpath(fullPath)) {
            dir.mkpath(fullPath + "\\Frontend");
            dir.mkpath(fullPath + "\\Backend");
            qDebug() << "Project created, closing the window";
            this->close();
        }
        else {
            QMessageBox::warning(this, "Error", "Failed to create project directory!");
        }
    }
    else {
        QMessageBox::information(this, "Cancelled", "Project creation cancelled.");
    }
}