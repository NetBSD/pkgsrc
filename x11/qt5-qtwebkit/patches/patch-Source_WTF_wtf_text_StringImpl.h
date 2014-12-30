$NetBSD: patch-Source_WTF_wtf_text_StringImpl.h,v 1.1 2014/12/30 17:23:47 adam Exp $

--- Source/WTF/wtf/text/StringImpl.h.orig	2013-11-27 01:01:21.000000000 +0000
+++ Source/WTF/wtf/text/StringImpl.h
@@ -24,6 +24,7 @@
 #define StringImpl_h
 
 #include <limits.h>
+#include <unistd.h>
 #include <wtf/ASCIICType.h>
 #include <wtf/Forward.h>
 #include <wtf/StdLibExtras.h>
