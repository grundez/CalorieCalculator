QT += core testlib

CONFIG += console c++17
CONFIG -= app_bundle

INCLUDEPATH += ../CalorieCalculator

SOURCES += tst_testcaloriecalculator.cpp \
           ../CalorieCalculator/caloriecalculator.cpp

HEADERS += ../CalorieCalculator/caloriecalculator.h
