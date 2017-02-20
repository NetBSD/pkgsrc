$NetBSD: patch-konq-plugins_validators_tidy__validator.cpp,v 1.1 2017/02/20 09:35:17 wiz Exp $

tidy-5.x compatibility.

--- konq-plugins/validators/tidy_validator.cpp.orig	2015-12-08 07:04:21.000000000 +0000
+++ konq-plugins/validators/tidy_validator.cpp
@@ -25,8 +25,8 @@
 
 #include <kdebug.h>
 
-#include <buffio.h>
 #include <tidy.h>
+#include <tidybuffio.h>
 
 #include <config-konq-validator.h>
 
