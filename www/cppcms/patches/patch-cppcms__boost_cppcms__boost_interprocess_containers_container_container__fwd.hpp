$NetBSD: patch-cppcms__boost_cppcms__boost_interprocess_containers_container_container__fwd.hpp,v 1.1 2013/07/16 10:12:48 joerg Exp $

--- cppcms_boost/cppcms_boost/interprocess/containers/container/container_fwd.hpp.orig	2010-05-14 13:53:00.000000000 +0000
+++ cppcms_boost/cppcms_boost/interprocess/containers/container/container_fwd.hpp
@@ -15,6 +15,8 @@
 #  pragma once
 #endif
 
+#include <utility>
+
 //////////////////////////////////////////////////////////////////////////////
 //                        Standard predeclarations
 //////////////////////////////////////////////////////////////////////////////
@@ -32,22 +34,6 @@ namespace bi = cppcms_boost::intrusive;
 
 }}}
 
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
 
 //////////////////////////////////////////////////////////////////////////////
