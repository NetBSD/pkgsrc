$NetBSD: patch-qtwebkit_Source_WTF_wtf_text_StringImpl.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

--- qtwebkit/Source/WTF/wtf/text/StringImpl.h.orig	2013-11-27 01:01:21.000000000 +0000
+++ qtwebkit/Source/WTF/wtf/text/StringImpl.h
@@ -24,6 +24,7 @@
 #define StringImpl_h
 
 #include <limits.h>
+#include <unistd.h>
 #include <wtf/ASCIICType.h>
 #include <wtf/Forward.h>
 #include <wtf/StdLibExtras.h>
