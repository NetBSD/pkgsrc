$NetBSD: patch-security_manager_boot_src_CertBlocklist.cpp,v 1.1 2015/04/10 05:40:36 martin Exp $

See https://bugzilla.mozilla.org/show_bug.cgi?id=1153090

--- security/manager/boot/src/CertBlocklist.cpp.orig	2015-04-03 04:30:09.000000000 +0200
+++ security/manager/boot/src/CertBlocklist.cpp	2015-04-10 07:30:39.000000000 +0200
@@ -87,7 +87,7 @@ CertBlocklistItem::Hash() const
   // there's no requirement for a serial to be as large as 32 bits; if it's
   // smaller, fall back to the first octet (otherwise, the last four)
   if (serialLength >= 4) {
-    hash = *(uint32_t *)(mSerialData + serialLength - 4);
+    memcpy(&hash, mSerialData + serialLength - 4, 4);
   } else {
     hash = *mSerialData;
   }
