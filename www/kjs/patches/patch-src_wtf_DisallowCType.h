$NetBSD: patch-src_wtf_DisallowCType.h,v 1.1 2016/08/21 22:27:17 markd Exp $

--- src/wtf/DisallowCType.h.orig	2013-05-03 23:51:02.000000000 +0000
+++ src/wtf/DisallowCType.h
@@ -54,6 +54,7 @@
 #undef tolower
 #undef toupper
 
+#ifndef _LIBCPP_VERSION
 #define isalnum WTF_Please_use_ASCIICType_instead_of_ctype_see_comment_in_ASCIICType_h
 #define isalpha WTF_Please_use_ASCIICType_instead_of_ctype_see_comment_in_ASCIICType_h
 #define isascii WTF_Please_use_ASCIICType_instead_of_ctype_see_comment_in_ASCIICType_h
@@ -70,5 +71,6 @@
 #define toascii WTF_Please_use_ASCIICType_instead_of_ctype_see_comment_in_ASCIICType_h
 #define tolower WTF_Please_use_ASCIICType_instead_of_ctype_see_comment_in_ASCIICType_h
 #define toupper WTF_Please_use_ASCIICType_instead_of_ctype_see_comment_in_ASCIICType_h
+#endif
 
 #endif
