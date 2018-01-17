$NetBSD: patch-src_tools_moc_main.cpp,v 1.1 2018/01/17 18:37:34 markd Exp $

--- src/tools/moc/main.cpp.orig	2015-05-07 14:14:44.000000000 +0000
+++ src/tools/moc/main.cpp
@@ -190,6 +190,10 @@ int runMoc(int _argc, char **_argv)
 
     // Workaround a bug while parsing the boost/type_traits/has_operator.hpp header. See QTBUG-22829
     pp.macros["BOOST_TT_HAS_OPERATOR_HPP_INCLUDED"];
+    pp.macros["BOOST_LEXICAL_CAST_INCLUDED"];
+    pp.macros["BOOST_NEXT_PRIOR_HPP_INCLUDED"];
+    pp.macros["BOOST_TYPE_TRAITS_HPP"];
+    pp.macros["_SYS_SYSMACROS_H_OUTER"];
 
     QByteArray filename;
     QByteArray output;
