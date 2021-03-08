QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GeneralType.cpp \
    addinformationwindow.cpp \
    addpetwindow.cpp \
    adminwindow.cpp \
    authorizationWindow.cpp \
    client.cpp \
    clientWindow.cpp \
    main.cpp \
    register_distributor_window.cpp \
    registrationWindow.cpp \
    registration_for_procedures_window.cpp \
    workerwindow.cpp

HEADERS += \
    GeneralType.h \
    Pet.h \
    addinformationwindow.h \
    addpetwindow.h \
    adminwindow.h \
    authorizationWindow.h \
    client.h \
    clientWindow.h \
    register_distributor_window.h \
    registrationWindow.h \
    registration_for_procedures_window.h \
    worker.h \
    workerwindow.h

FORMS += \
    addinformationwindow.ui \
    addpetwindow.ui \
    adminwindow.ui \
    authorizationWindow.ui \
    clientWindow.ui \
    mainwWndow.ui \
    register_distributor_window.ui \
    registrationWindow.ui \
    registration_for_procedures_window.ui \
    workerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
