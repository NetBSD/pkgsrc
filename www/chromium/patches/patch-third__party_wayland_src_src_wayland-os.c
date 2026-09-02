$NetBSD: patch-third__party_wayland_src_src_wayland-os.c,v 1.6 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/wayland/src/src/wayland-os.c.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/wayland/src/src/wayland-os.c
@@ -106,6 +106,24 @@ wl_os_socket_peercred(int sockfd, uid_t 
 #endif
 	return 0;
 }
+#elif defined(__NetBSD__)
+#ifndef SOL_LOCAL
+#define SOL_LOCAL (0)
+#endif
+int
+wl_os_socket_peercred(int sockfd, uid_t *uid, gid_t *gid, pid_t *pid)
+{
+	socklen_t len;
+	struct sockcred ucred;
+
+	len = sizeof(ucred);
+	if (getsockopt(sockfd, SOL_LOCAL, LOCAL_CREDS, &ucred, &len) < 0)
+		return -1;
+	*uid = ucred.sc_uid;
+	*gid = ucred.sc_gid;
+	*pid = 0;
+	return 0;
+}
 #elif defined(SO_PEERCRED)
 int
 wl_os_socket_peercred(int sockfd, uid_t *uid, gid_t *gid, pid_t *pid)
