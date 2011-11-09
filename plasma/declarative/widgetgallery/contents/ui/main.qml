/*
*   Copyright (C) 2011 by Daker Fernandes Pinheiro <dakerfp@gmail.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU Library General Public License as
*   published by the Free Software Foundation; either version 2, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details
*
*   You should have received a copy of the GNU Library General Public
*   License along with this program; if not, write to the
*   Free Software Foundation, Inc.,
*   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

import QtQuick 1.0
import org.kde.plasma.components 0.1

Item {
    property int minimumWidth: 300
    property int minimumHeight: 400

    ToolBar {
        id: toolBar
        z: 10
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
    }


    Flickable {
        id: page
        clip: true

        anchors {
            top: toolBar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        contentWidth: pageStack.currentPage.implicitWidth
        contentHeight: pageStack.currentPage.implicitHeight

        PageStack {
            id: pageStack
            toolBar: toolBar
            width: page.width
            height: currentPage.implicitHeight
            initialPage: Qt.createComponent("Menu.qml")
        }

    }

    ScrollBar {
        id: horizontalScrollBar

	    stepSize: 30

        flickableItem: page
        orientation: Qt.Horizontal
        anchors {
            left: parent.left
            right: verticalScrollBar.left
            bottom: parent.bottom
        }
    }

    ScrollBar {
        id: verticalScrollBar

	    stepSize: 30

        orientation: Qt.Vertical
        flickableItem: page
        anchors {
            top: toolBar.bottom
            right: parent.right
            bottom: horizontalScrollBar.top
        }
    }
}
