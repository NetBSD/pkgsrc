$NetBSD: patch-rfc4331quotas-modules_dav_main_mod_dav.h,v 1.1 2023/04/21 13:52:33 manu Exp $

RFC4331 quotas from upstream trunk
http://svn.apache.org/viewvc?view=revision&revision=1907974
http://svn.apache.org/viewvc?view=revision&revision=1907984
http://svn.apache.org/viewvc?view=revision&revision=1907989
http://svn.apache.org/viewvc?view=revision&revision=1908143
http://svn.apache.org/viewvc?view=revision&revision=1908144

--- modules/dav/main/mod_dav.h	(revision 1907973)
+++ modules/dav/main/mod_dav.h	(revision 1907974)
@@ -1172,6 +1172,10 @@
     DAV_PROPID_workspace,
     DAV_PROPID_workspace_checkout_set,
 
+    /* RFC 4331 quotas */
+    DAV_PROPID_quota_available_bytes,
+    DAV_PROPID_quota_used_bytes,
+
     DAV_PROPID_END
 };
 
Index: modules/dav/fs/quota.c
===================================================================
