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
import org.kde.plasma.components 0.1 as PlasmaComponents

PlasmaComponents.Page {
    height: childrenRect.height
    tools: PlasmaComponents.ToolBarLayout {
        spacing: 5
        PlasmaComponents.ToolButton {
            iconSource: "go-previous"
            onClicked: pageStack.pop()
        }
        PlasmaComponents.Button {
            text: "Button"
        }
        PlasmaComponents.TextField {}
    }

    Flickable {
        id: flickable
        contentWidth: column.width
        contentHeight: column.height
        clip: true
        anchors.fill: parent

        Column {
            id: column
            spacing: 20

            Text {
                font.pixelSize: 20
                text: "Buttons"
            }

            PlasmaComponents.Button {
                id: bt1
                width: 140
                height: 30
                text: "Button"

                onClicked: {
                    console.log("Clicked");
                }

                Keys.onTabPressed: bt2.forceActiveFocus();
            }

            PlasmaComponents.Button {
                id: bt2
                width: 140
                height: 30
                text: "Checkable Button"
                checkable: true

                onCheckedChanged: {
                    if (checked)
                        console.log("Button Checked");
                    else
                        console.log("Button Unchecked");
                }

                Keys.onTabPressed: bt3.forceActiveFocus();
            }

            PlasmaComponents.Button {
                id: bt3
                width: 140
                height: 30
                text: "Different Font"
                font {
                    pixelSize: 20
                    family: "Helvetica"
                }

                Keys.onTabPressed: bt4.forceActiveFocus();
            }

            PlasmaComponents.Button {
                id: bt4
                width: 140
                height: 30
                text: "Icon Button"
                iconSource: "/home/dakerfp/work/comics-reader/ui/images/random.png"

                Keys.onTabPressed: bt5.forceActiveFocus();
            }

            PlasmaComponents.Button {
                id: bt5
                width: 140
                height: 30
                iconSource: "/home/dakerfp/work/comics-reader/ui/images/random.png"

                Keys.onTabPressed: bt1.forceActiveFocus();
            }

            PlasmaComponents.Button {
                width: 140
                height: 30
                text: "Disabled Button"
                enabled: false
            }
        }
    }

    PlasmaComponents.ScrollBar {
        id: horizontalScrollBar

        flickableItem: flickable
        orientation: Qt.Horizontal
        anchors {
            left: parent.left
            right: verticalScrollBar.left
            bottom: parent.bottom
        }
    }

    PlasmaComponents.ScrollBar {
        id: verticalScrollBar

        orientation: Qt.Vertical
        flickableItem: flickable
        anchors {
            top: parent.top
            right: parent.right
            bottom: horizontalScrollBar.top
        }
    }
}