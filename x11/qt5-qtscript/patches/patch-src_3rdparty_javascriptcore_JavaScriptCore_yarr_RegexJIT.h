$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_yarr_RegexJIT.h,v 1.1 2015/08/30 10:00:57 markd Exp $

pick up correct pcre.h

--- src/3rdparty/javascriptcore/JavaScriptCore/yarr/RegexJIT.h.orig	2014-12-05 16:24:12.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/yarr/RegexJIT.h
@@ -34,7 +34,7 @@
 #include "RegexPattern.h"
 #include <UString.h>
 
-#include <pcre.h>
+#include <pcre/pcre.h>
 struct JSRegExp; // temporary, remove when fallback is removed.
 
 #if CPU(X86) && !COMPILER(MSVC)
