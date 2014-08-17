#include "widget.h"
#include <QtGui/QApplication>
#include <QtCore/QTextCodec>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QSystemSemaphore sema("ServerKey",1,QSystemSemaphore::Open);
	sema.acquire();
	QSharedMemory mem("ServerObject");

	if (!mem.create(1))
	{
		QMessageBox::warning(NULL, "error", 
			"A server has already been running.");
		sema.release();
		return 0;
	}
	sema.release();

	Widget w;
	w.show();
	return a.exec();
}
