$NetBSD: patch-src_tools_moc_main.cpp,v 1.2 2015/10/26 19:03:59 adam Exp $

rh#756395, https://bugreports.qt-project.org/browse/QTBUG-22829

--- src/tools/moc/main.cpp.orig	2013-11-27 01:01:11.000000000 +0000
+++ src/tools/moc/main.cpp
@@ -192,6 +192,7 @@ int runMoc(int argc, char **argv)
     Moc moc;
     pp.macros["Q_MOC_RUN"];
     pp.macros["__cplusplus"];
+    pp.macros["BOOST_TT_HAS_OPERATOR_HPP_INCLUDED"];
 
     // Don't stumble over GCC extensions
     Macro dummyVariadicFunctionMacro;
