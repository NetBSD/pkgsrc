$NetBSD: patch-khotkeys_libkhotkeysprivate_windows__helper_window__selection__rules.cpp,v 1.1 2020/03/26 21:48:12 joerg Exp $

--- khotkeys/libkhotkeysprivate/windows_helper/window_selection_rules.cpp.orig	2020-03-26 12:05:58.251568485 +0000
+++ khotkeys/libkhotkeysprivate/windows_helper/window_selection_rules.cpp
@@ -91,7 +91,7 @@ bool Windowdef_simple::is_substr_match( 
         case NOT_IMPORTANT :
           return true;
         case CONTAINS :
-          return str1_P.contains( str2_P ) > 0;
+          return str1_P.contains( str2_P );
         case IS :
           return str1_P == str2_P;
         case REGEXP :
