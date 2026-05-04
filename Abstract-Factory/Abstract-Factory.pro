QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ClassUnit.h \
    Factory.h \
    MethodUnit.h \
    PrintOperatorUnit.h \
    Unit.h \
    cppClassUnit.h \
    cppMethodUnit.h \
    cppPrintOperatorUnit.h \
    csClassUnit.h \
    csMethodUnit.h \
    csPrintOperatorUnit.h \
    javaClassUnit.h \
    javaMethodUnit.h \
    javaPrintOperatorUnit.h \
    сppMethodUnit.h
