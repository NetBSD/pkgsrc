$NetBSD: patch-src_3rdparty_webkit_Source_JavaScriptCore_wtf_NullPtr.h,v 1.4 2015/01/27 05:20:10 dbj Exp $

--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/NullPtr.h.orig	2014-04-10 18:37:11.000000000 +0000
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/NullPtr.h
@@ -39,6 +39,16 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
 
 #define HAVE_NULLPTR 1
 
+#if __APPLE__
+#include <AvailabilityMacros.h>
+#if MAC_OS_X_VERSION_MIN_REQUIRED <= MAC_OS_X_VERSION_10_8
+namespace std
+{
+	typedef decltype(nullptr) nullptr_t;
+}
+#endif
+#endif
+
 #else
 
 namespace std {
