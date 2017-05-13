/* This file is part of qjson
  *
  * Copyright (C) 2009 Flavio Castelli <flavio@castelli.name>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Lesser General Public
  * License version 2.1, as published by the Free Software Foundation.
  *
  *
  * This library is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  * Lesser General Public License for more details.
  *
  * You should have received a copy of the GNU Lesser General Public License
  * along with this library; see the file COPYING.LIB.  If not, write to
  * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  * Boston, MA 02110-1301, USA.
  */

#ifndef QOBJECTHELPER_H
#define QOBJECTHELPER_H


#include <QStringList>
#include <QVariantMap>
#include <QJsonObject>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
class QObject;
QT_END_NAMESPACE

class  QObjectHelper {
public:
	QObjectHelper();
	~QObjectHelper();

	/**
	* This method converts a QObject instance into a QVariantMap.
	*
	* @param object The QObject instance to be converted.
	* @param ignoredProperties Properties that won't be converted.
	*/
	static QVariantMap qobject2qvariant( const QObject* object,
										 const QStringList& ignoredProperties = QStringList(QString(QLatin1String("objectName"))));

	static QJsonObject qobject2qjson( const QObject* object,
										 const QStringList& ignoredProperties = QStringList(QString(QLatin1String("objectName"))));

	/**
	* This method converts a QVariantMap instance into a QObject
	*
	* @param variant Attributes to assign to the object.
	* @param object The QObject instance to update.
	*/
	static void qvariant2qobject(const QVariantMap& variant, QObject* object);

	static void qjson2qobject(const QJsonObject& qJsonObject, QObject* object);

private:
	Q_DISABLE_COPY(QObjectHelper)
//	class QObjectHelperPrivate;
//	QObjectHelperPrivate* const d;
};


#endif // QOBJECTHELPER_H
