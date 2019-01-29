$NetBSD: patch-js_xpconnect_src_XPCMaps.cpp,v 1.2 2019/01/29 16:28:22 ryoon Exp $

Avoid alignement issues, see bugzilla
see https://bugzilla.mozilla.org/show_bug.cgi?id=1434726

--- js/xpconnect/src/XPCMaps.cpp.orig	2019-01-18 00:20:42.000000000 +0000
+++ js/xpconnect/src/XPCMaps.cpp
@@ -21,7 +21,13 @@ using namespace mozilla;
 // nsID, not the hash of the pointer to the nsID.
 
 static PLDHashNumber HashIIDPtrKey(const void* key) {
+#ifdef __sparc__
+ uintptr_t v;
+ memcpy(&v, key, sizeof(v));
+ return HashGeneric(&v);
+#else
   return HashGeneric(*((uintptr_t*)key));
+#endif
 }
 
 static bool MatchIIDPtrKey(const PLDHashEntryHdr* entry, const void* key) {
