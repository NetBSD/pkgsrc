$NetBSD: patch-mozilla_netwerk_base_public_nsNetUtil.h,v 1.1 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/netwerk/base/public/nsNetUtil.h.orig	2015-03-09 05:34:54.000000000 +0000
+++ mozilla/netwerk/base/public/nsNetUtil.h
@@ -13,6 +13,7 @@
 #include "nsMemory.h"
 #include "nsCOMPtr.h"
 #include "prio.h" // for read/write flags, permissions, etc.
+#include "prnetdb.h"
 #include "nsHashKeys.h"
 
 #include "plstr.h"
@@ -2869,6 +2870,26 @@ NS_IsSrcdocChannel(nsIChannel *aChannel)
 bool NS_IsReasonableHTTPHeaderValue(const nsACString& aValue);
 
 /**
+ * Return a host endian value decoded from network byte order,
+ * accessed in an alignement safe way.
+ */
+inline uint16_t NS_decodeN16(const void *bytes)
+{
+    uint16_t tmp;
+
+    memcpy(&tmp, bytes, sizeof tmp);
+    return PR_ntohs(tmp);
+}
+
+inline uint32_t NS_decodeN32(const void *bytes)
+{
+    uint32_t tmp;
+
+    memcpy(&tmp, bytes, sizeof tmp);
+    return PR_ntohl(tmp);
+}
+
+/**
  * Return true if the given string is a valid HTTP token per RFC 2616 section
  * 2.2.
  */
