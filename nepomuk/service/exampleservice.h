/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  Vishesh Handa <handa.vish@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef NEPOMUKEXAMPLESERVICE_H
#define NEPOMUKEXAMPLESERVICE_H

#include <Nepomuk2/Service>

namespace Nepomuk2 {

    class ExampleService : public Service
    {
        Q_OBJECT
    public:
        ExampleService( QObject * parent = 0, const QList<QVariant>& args = QList<QVariant>() );
        ~ExampleService();

    public Q_SLOTS:
        Q_SCRIPTABLE void test();
    };

}

#endif // NEPOMUKEXAMPLESERVICE_H
