$NetBSD: patch-js_xpconnect_src_XPCMaps.cpp,v 1.1 2018/11/07 12:55:11 martin Exp $

Avoid alignement issues, see bugzilla
see https://bugzilla.mozilla.org/show_bug.cgi?id=1434726

--- js/xpconnect/src/XPCMaps.cpp.orig	2018-10-31 01:08:09.000000000 +0100
+++ js/xpconnect/src/XPCMaps.cpp	2018-11-07 13:03:15.754241064 +0100
@@ -23,7 +23,13 @@ using namespace mozilla;
 static PLDHashNumber
 HashIIDPtrKey(const void* key)
 {
+#ifdef __sparc__
+    uintptr_t v;
+    memcpy(&v, key, sizeof(v));
+    return HashGeneric(&v);
+#else
     return HashGeneric(*((uintptr_t*)key));
+#endif
 }
 
 static bool
