QT       += core gui network printsupport
QT       += sql
QT       += widgets
QT       += core gui serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduino1.cpp \
    conge.cpp \
    connectioncpp.cpp \
    main.cpp \
    login.cpp \
    mainwindow.cpp \
    mainwindow1.cpp \
    personnel.cpp \
    produit.cpp \
    produits.cpp \
    qcustomplot.cpp \
    reclamation.cpp \
    smtp.cpp \
    visite.cpp \
    windowcommidites.cpp \
    windowpersonnel.cpp \
    windowreclamation.cpp \
    windowvisite.cpp

HEADERS += \
    arduino.h \
    arduino1.h \
    conge.h \
    connectioncpp.h \
    login.h \
    mainwindow.h \
    mainwindow1.h \
    personnel.h \
    produit.h \
    produits.h \
    qcustomplot.h \
    reclamation.h \
    smtp.h \
    visite.h \
    windowcommidites.h \
    windowpersonnel.h \
    windowreclamation.h \
    windowvisite.h

FORMS += \
    login.ui \
    mainwindow.ui \
    mainwindow1.ui \
    windowcommidites.ui \
    windowpersonnel.ui \
    windowreclamation.ui \
    windowvisite.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    projetcpp.pro

DISTFILES += \
    projetcpp.pro.user \
    projetcpp.pro.user.991943f \
    projetcpp.pro.user.e7dc2f4
