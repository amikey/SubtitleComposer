/*
 * Copyright (C) 2010-2018 Mladen Milinkovic <max@smoothware.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "krecentfilesactionext.h"

KRecentFilesActionExt::KRecentFilesActionExt(QObject *parent)
	: KRecentFilesAction(parent)
{
}


KRecentFilesActionExt::~KRecentFilesActionExt()
{
}

QString
KRecentFilesActionExt::encodingForUrl(const QUrl &url) const
{
	static const QRegExp rx("encoding=([^&]*)");
	const QUrl urlClean = url.adjusted(QUrl::RemoveQuery | QUrl::RemoveFragment);

	foreach(const QUrl &urlAction, urls()) {
		if(urlClean != urlAction.adjusted(QUrl::RemoveQuery | QUrl::RemoveFragment))
			continue;
		if(rx.indexIn(urlAction.query()) >= 0)
			return rx.cap(1);
	}
	return QString();
}