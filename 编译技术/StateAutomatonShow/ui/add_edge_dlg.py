# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'add_edge_dlg.ui'
#
# Created by: PyQt5 UI code generator 5.15.9
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_addEdgeDlg(object):
    def setupUi(self, addEdgeDlg):
        addEdgeDlg.setObjectName("addEdgeDlg")
        addEdgeDlg.resize(248, 154)
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(addEdgeDlg)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_2 = QtWidgets.QLabel(addEdgeDlg)
        font = QtGui.QFont()
        font.setFamily("霞鹜文楷 屏幕阅读版 R")
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.horizontalLayout.addWidget(self.label_2)
        self.lineEdit_stA = QtWidgets.QLineEdit(addEdgeDlg)
        font = QtGui.QFont()
        font.setFamily("霞鹜文楷 屏幕阅读版 R")
        self.lineEdit_stA.setFont(font)
        self.lineEdit_stA.setReadOnly(False)
        self.lineEdit_stA.setObjectName("lineEdit_stA")
        self.horizontalLayout.addWidget(self.lineEdit_stA)
        self.label = QtWidgets.QLabel(addEdgeDlg)
        font = QtGui.QFont()
        font.setFamily("霞鹜文楷 屏幕阅读版 R")
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.horizontalLayout.addWidget(self.label)
        self.lineEdit_edA = QtWidgets.QLineEdit(addEdgeDlg)
        font = QtGui.QFont()
        font.setFamily("霞鹜文楷 屏幕阅读版 R")
        self.lineEdit_edA.setFont(font)
        self.lineEdit_edA.setReadOnly(False)
        self.lineEdit_edA.setObjectName("lineEdit_edA")
        self.horizontalLayout.addWidget(self.lineEdit_edA)
        self.verticalLayout_2.addLayout(self.horizontalLayout)
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label_3 = QtWidgets.QLabel(addEdgeDlg)
        font = QtGui.QFont()
        font.setFamily("霞鹜文楷 屏幕阅读版 R")
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.horizontalLayout_2.addWidget(self.label_3)
        self.lineEdit_inputA = QtWidgets.QLineEdit(addEdgeDlg)
        font = QtGui.QFont()
        font.setFamily("霞鹜文楷 屏幕阅读版 R")
        self.lineEdit_inputA.setFont(font)
        self.lineEdit_inputA.setObjectName("lineEdit_inputA")
        self.horizontalLayout_2.addWidget(self.lineEdit_inputA)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_4 = QtWidgets.QLabel(addEdgeDlg)
        font = QtGui.QFont()
        font.setFamily("霞鹜文楷 屏幕阅读版 R")
        self.label_4.setFont(font)
        self.label_4.setObjectName("label_4")
        self.horizontalLayout_3.addWidget(self.label_4)
        self.lineEdit_inputB = QtWidgets.QLineEdit(addEdgeDlg)
        font = QtGui.QFont()
        font.setFamily("霞鹜文楷 屏幕阅读版 R")
        self.lineEdit_inputB.setFont(font)
        self.lineEdit_inputB.setReadOnly(False)
        self.lineEdit_inputB.setObjectName("lineEdit_inputB")
        self.horizontalLayout_3.addWidget(self.lineEdit_inputB)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.verticalLayout_2.addLayout(self.verticalLayout)
        self.buttonBox = QtWidgets.QDialogButtonBox(addEdgeDlg)
        font = QtGui.QFont()
        font.setFamily("霞鹜文楷 屏幕阅读版 R")
        self.buttonBox.setFont(font)
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.verticalLayout_2.addWidget(self.buttonBox)
        self.verticalLayout_3.addLayout(self.verticalLayout_2)

        self.retranslateUi(addEdgeDlg)
        self.buttonBox.accepted.connect(addEdgeDlg.accept) # type: ignore
        self.buttonBox.rejected.connect(addEdgeDlg.reject) # type: ignore
        QtCore.QMetaObject.connectSlotsByName(addEdgeDlg)

    def retranslateUi(self, addEdgeDlg):
        _translate = QtCore.QCoreApplication.translate
        addEdgeDlg.setWindowTitle(_translate("addEdgeDlg", "EdgeInfo"))
        self.label_2.setText(_translate("addEdgeDlg", "起点"))
        self.lineEdit_stA.setPlaceholderText(_translate("addEdgeDlg", "必填"))
        self.label.setText(_translate("addEdgeDlg", "终点"))
        self.lineEdit_edA.setPlaceholderText(_translate("addEdgeDlg", "必填"))
        self.label_3.setText(_translate("addEdgeDlg", "输入"))
        self.lineEdit_inputA.setPlaceholderText(_translate("addEdgeDlg", "正向边信息,必填"))
        self.label_4.setText(_translate("addEdgeDlg", "输入"))
        self.lineEdit_inputB.setPlaceholderText(_translate("addEdgeDlg", "反向边信息,可不填"))
