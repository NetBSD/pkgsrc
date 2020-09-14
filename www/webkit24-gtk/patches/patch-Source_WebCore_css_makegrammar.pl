$NetBSD: patch-Source_WebCore_css_makegrammar.pl,v 1.1 2020/09/14 18:19:16 joerg Exp $

Don't remove header created by bison, it is referenced from the parser in
newer version.

--- Source/WebCore/css/makegrammar.pl.orig	2020-09-12 19:54:15.554993196 +0000
+++ Source/WebCore/css/makegrammar.pl
@@ -91,5 +91,5 @@ print HEADER "#endif\n";
 close HEADER;
 
 unlink("$fileBase.cpp.h");
-unlink("$fileBase.hpp");
+#unlink("$fileBase.hpp");
 
