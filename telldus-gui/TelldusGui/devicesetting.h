//
// C++ Interface: devicesetting
//
// Description:
//
//
// Author: Micke Prag <micke.prag@telldus.se>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef DEVICESETTING_H
#define DEVICESETTING_H

#include <QWidget>

class Device;

/**
	@author Micke Prag <micke.prag@telldus.se>
*/
class DeviceSetting : public QWidget
{
Q_OBJECT
public:
	DeviceSetting(Device *device, QWidget *parent = 0);

	virtual ~DeviceSetting();

public slots:
	virtual void saveParameters() = 0;
	void addProtocolMatch( const QString &protocol, const QString &model );

private slots:
	void setProtocolValue( const QString &name, const QString &value, const QString &protocol, const QString &model );
	virtual void setValue( const QString &name, const QString &value ) = 0;

protected:
	Device *p_device;

private:
	QList<QString> acceptedProtocolModel;

};

#endif
