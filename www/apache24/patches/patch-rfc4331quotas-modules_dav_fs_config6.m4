$NetBSD: patch-rfc4331quotas-modules_dav_fs_config6.m4,v 1.1 2023/04/21 13:52:33 manu Exp $

RFC4331 quotas from upstream trunk
http://svn.apache.org/viewvc?view=revision&revision=1907974
http://svn.apache.org/viewvc?view=revision&revision=1907984
http://svn.apache.org/viewvc?view=revision&revision=1907989
http://svn.apache.org/viewvc?view=revision&revision=1908143
http://svn.apache.org/viewvc?view=revision&revision=1908144

--- modules/dav/fs/config6.m4	(revision 1907973)
+++ modules/dav/fs/config6.m4	(revision 1907974)
@@ -2,7 +2,7 @@
 
 APACHE_MODPATH_INIT(dav/fs)
 
-dav_fs_objects="mod_dav_fs.lo dbm.lo lock.lo repos.lo"
+dav_fs_objects="mod_dav_fs.lo dbm.lo lock.lo quota.lo repos.lo"
 
 if test "x$enable_dav" != "x"; then
   dav_fs_enable=$enable_dav
Index: modules/dav/fs/mod_dav_fs.c
===================================================================
