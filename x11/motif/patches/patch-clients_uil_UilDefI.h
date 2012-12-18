$NetBSD: patch-clients_uil_UilDefI.h,v 1.1 2012/12/18 11:25:34 jperkin Exp $

As GNU bison is pulled in on Solaris we need yystype.

--- clients/uil/UilDefI.h.orig	2012-12-18 11:09:36.702277373 +0000
+++ clients/uil/UilDefI.h	2012-12-18 11:10:06.203453714 +0000
@@ -270,7 +270,7 @@
 #include "UilIODef.h"
 #include "UilDiagDef.h"
 #include "UilSarDef.h"
-#if defined(linux) || defined(__APPLE__)
+#if defined(linux) || defined(__APPLE__) || defined(__sun)
 #define YYSTYPE yystype
 #endif
 #include "UilLexPars.h"
