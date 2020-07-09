$NetBSD: patch-src_esi_VarState.cc,v 1.1 2020/07/09 20:57:11 otis Exp $

Fix undeclared index() by including the proper header file.

--- src/esi/VarState.cc.orig	2020-07-09 19:37:38.879095702 +0000
+++ src/esi/VarState.cc
@@ -12,6 +12,9 @@
 #include "esi/VarState.h"
 #include "fatal.h"
 #include "HttpReply.h"
+#if HAVE_STRINGS_H
+#include <strings.h>
+#endif
 
 char const *ESIVariableUserAgent::esiUserOs[]= {
     "WIN",
