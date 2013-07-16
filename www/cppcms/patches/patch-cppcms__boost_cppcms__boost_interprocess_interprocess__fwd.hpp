$NetBSD: patch-cppcms__boost_cppcms__boost_interprocess_interprocess__fwd.hpp,v 1.1 2013/07/16 10:12:48 joerg Exp $

--- cppcms_boost/cppcms_boost/interprocess/interprocess_fwd.hpp.orig	2010-05-14 13:52:59.000000000 +0000
+++ cppcms_boost/cppcms_boost/interprocess/interprocess_fwd.hpp
@@ -19,6 +19,7 @@
 #include <cppcms_boost/interprocess/detail/workaround.hpp>
 
 #include <cstddef>
+#include <utility>
 
 //////////////////////////////////////////////////////////////////////////////
 //                        Standard predeclarations
@@ -35,22 +36,6 @@ namespace interprocess{
 namespace bi = cppcms_boost::intrusive;
 }}
 
-namespace std {
-
-template <class T>
-class allocator;
-
-template <class T>
-struct less;
-
-template <class T1, class T2>
-struct pair;
-
-template <class CharType> 
-struct char_traits;
-
-}  //namespace std {
-
 /// @endcond
 
 namespace cppcms_boost { namespace interprocess {
