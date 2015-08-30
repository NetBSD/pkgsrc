$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_yarr_RegexJIT.h,v 1.1 2015/08/30 10:04:08 markd Exp $

pick up correct pcre.h (if pcre package pulled in by gtk2 option)

--- src/3rdparty/javascriptcore/JavaScriptCore/yarr/RegexJIT.h	2014-04-11 06:37:12.000000000 +1200
+++ src/3rdparty/javascriptcore/JavaScriptCore/yarr/RegexJIT.h
@@ -34,7 +34,7 @@
 #include "RegexPattern.h"
 #include <UString.h>
 
-#include <pcre.h>
+#include <pcre/pcre.h>
 struct JSRegExp; // temporary, remove when fallback is removed.
 
 #if CPU(X86) && !COMPILER(MSVC)
