$NetBSD: patch-qtbase_tests_auto_widgets_itemviews_qtreewidgetitemiterator_qtreewidgetitemiterator.pro,v 1.1 2013/12/15 19:51:19 joerg Exp $

Consumes too much memory with Clang. As it is just a test case,
disable optimisation for all compiler.

--- qtbase/tests/auto/widgets/itemviews/qtreewidgetitemiterator/qtreewidgetitemiterator.pro.orig	2013-12-15 15:52:18.000000000 +0000
+++ qtbase/tests/auto/widgets/itemviews/qtreewidgetitemiterator/qtreewidgetitemiterator.pro
@@ -4,4 +4,6 @@ TARGET = tst_qtreewidgetitemiterator
 QT += widgets testlib
 SOURCES  += tst_qtreewidgetitemiterator.cpp
 
+QMAKE_CXXFLAGS_WARN_ON= -O0
+QMAKE_CXXFLAGS_WARN_OFF= -O0
 
