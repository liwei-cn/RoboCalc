#include "parameters.h"
#include "agent.h"
#include "myWorld.h"
#include "viewer/Viewer.h"

#include <cstdlib>
#include <cstring>
#include <sys/time.h>
#include <sys/stat.h>
#include <math.h>
#include <enki/PhysicalEngine.h>
#include <enki/robots/e-puck/EPuck.h>
#include <QtGui/QApplication>
#include <QtGui/QtGui>

using namespace Enki;
using namespace std;

class EnkiViewer : public ViewerWidget
{
protected:
	unsigned timeMultiplier;
	int timerId;
	myWorld* myworld;

public:
	EnkiViewer(myWorld* world, unsigned timeMultiplier = 1, QWidget *parent = 0) :
		ViewerWidget(world, parent),
		timeMultiplier(timeMultiplier)
	{
		myworld = world;
		timerId = startTimer(100);  //0.1s timer
        // Define viewer camera position and altitudes
        altitude= world->h;
        pos = QPointF(-world->w * 0.5, -world->h * 0);
	}

	virtual void timerEvent(QTimerEvent * event)
	{
		if (event->timerId() == timerId)
		{
			bool finished = false;
			for (unsigned i = 0; i < timeMultiplier; i++)
			{
				finished =  myworld->runStep();
				if (finished)
					break;
			}
			updateGL();

			if (finished)
				close();
		}
	}

	virtual void wheelEvent(QWheelEvent * event)   //zoom in or out the video through middle button of mouse
	{
		if (event->delta() > 0)
			timeMultiplier *= 2;
		else if (event->delta() < 0 && timeMultiplier > 1)
			timeMultiplier /= 2;
		setWindowTitle(QString(tr("Simulation running at %0 times real-time").arg(timeMultiplier)));
	}

    virtual void sceneCompletedHook()  //put some texts over the video
    {
        glColor3d(0,0,0);
//        renderText(10, height()-50, tr("rotate camera by moving mouse while pressing ctrl+left mouse button"));
//        renderText(10, height()-30, tr("move camera on x/y by moving mouse while pressing ctrl+shift+left mouse button"));
//        renderText(10, height()-10, tr("move camera on z by moving mouse while pressing ctrl+shift+right mouse button"));
        renderText(5, 15, QString(tr("Simulation running at %0 times real-time").arg(timeMultiplier)));
    }

};

int main(int argc, char* argv[])
{
	myWorld m_World(ArenaWidth, ArenaWidth, Color(0.9, 0.9, 0.9), MaximumStepSize);

	if (strcmp(argv[1], "viewer") == 0){
		unsigned timeMultiplier = 1;
		QApplication app(argc, argv);
		EnkiViewer viewer(&m_World, timeMultiplier);
		viewer.show();
		return app.exec();
	}
	else if (strcmp(argv[1], "noviewer") == 0){
		m_World.run();
		return 0;
	}
	else{
		std::cerr << "First argument must either be viewer or noviewer" << std::endl;
		return 2;
	}
}


