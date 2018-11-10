#include "rcprofilehelper.h"
#include <QtWidgets/QApplication>
#include "dlgnewprofilecreate.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	dlgNewProfileCreate w;
	w.show();
	return a.exec();
}
