$NetBSD: patch-qtbase_src_tools_moc_main.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

--- qtbase/src/tools/moc/main.cpp.orig	2013-11-27 01:01:11.000000000 +0000
+++ qtbase/src/tools/moc/main.cpp
@@ -192,6 +192,8 @@ int runMoc(int argc, char **argv)
     Moc moc;
     pp.macros["Q_MOC_RUN"];
     pp.macros["__cplusplus"];
+    // rh#756395, https://bugreports.qt-project.org/browse/QTBUG-22829
+    pp.macros["BOOST_TT_HAS_OPERATOR_HPP_INCLUDED"];
 
     // Don't stumble over GCC extensions
     Macro dummyVariadicFunctionMacro;
