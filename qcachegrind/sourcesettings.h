/* This file is part of KCachegrind.
   Copyright (c) 2009-2016 Josef Weidendorfer <Josef.Weidendorfer@gmx.de>

   KCachegrind is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public
   License as published by the Free Software Foundation, version 2.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

/*
 * Source annotation directory settings config page
 */

#ifndef SOURCESETTINGS_H
#define SOURCESETTINGS_H

#include "configpage.h"
#include "ui_sourcesettings.h"

class TraceData;
class QTreeWidgetItem;

class SourceSettings: public ConfigPage
{
    Q_OBJECT

public:
    SourceSettings(TraceData* data, QWidget* parent);
    ~SourceSettings() override {}

    bool check(QString&, QString&) override;
    void accept() override;
    void activate(QString s) override;

public Q_SLOTS:
    void addClicked();
    void deleteClicked();
    void browseClicked();
    void dirListItemChanged(QTreeWidgetItem*, QTreeWidgetItem*);
    void objectChanged(QString);
    void dirEditChanged(QString);

private:
    void update();

    Ui::SourceSettings ui;
    QTreeWidgetItem* _current;
    QString _always;
};


#endif // SOURCESETTINGS_H
