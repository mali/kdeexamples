#!/usr/bin/env python
# coding=UTF-8
#
# Generated by pykdeuic4 from textbrowser.ui on Sat Jan  1 21:06:43 2011
#
# WARNING! All changes to this file will be lost.
from PyKDE4 import kdecore
from PyKDE4 import kdeui
from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName(_fromUtf8("Form"))
        Form.resize(400, 300)
        self.verticalLayout = QtGui.QVBoxLayout(Form)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.textWidget = KTextEdit(Form)
        self.textWidget.setEnabled(True)
        self.textWidget.setReadOnly(True)
        self.textWidget.setAcceptRichText(False)
        self.textWidget.setObjectName(_fromUtf8("textWidget"))
        self.verticalLayout.addWidget(self.textWidget)
        self.downloadButton = KPushButton(Form)
        self.downloadButton.setObjectName(_fromUtf8("downloadButton"))
        self.verticalLayout.addWidget(self.downloadButton)
        self.clearButton = KPushButton(Form)
        self.clearButton.setObjectName(_fromUtf8("clearButton"))
        self.verticalLayout.addWidget(self.clearButton)

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        Form.setWindowTitle(kdecore.i18n(_fromUtf8("Form")))
        self.downloadButton.setText(kdecore.i18n(_fromUtf8("Start example")))
        self.clearButton.setText(kdecore.i18n(_fromUtf8("Clear")))

from PyKDE4.kdeui import KTextEdit, KPushButton
