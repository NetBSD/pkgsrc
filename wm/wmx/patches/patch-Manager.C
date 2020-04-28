$NetBSD: patch-Manager.C,v 1.1 2020/04/28 15:28:57 nikita Exp $

--- Manager.C.orig	2014-11-16 19:34:19.000000000 +0000
+++ Manager.C
@@ -65,6 +65,12 @@ Boolean ignoreBadWindowErrors;
 
 implementPList(ClientList, Client);
 
+#ifdef __OpenBSD__
+extern "C" {
+	int      snprintf(char *, size_t, const char *, ...);
+}
+#endif
+
 #if CONFIG_GROUPS != False
 implementPList(ListList, ClientList);
 #endif
