$NetBSD: patch-rfc4331quotas-modules_dav_fs_mod_dav_fs.dsp,v 1.1 2023/04/21 13:52:33 manu Exp $

RFC4331 quotas from upstream trunk
http://svn.apache.org/viewvc?view=revision&revision=1907974
http://svn.apache.org/viewvc?view=revision&revision=1907984
http://svn.apache.org/viewvc?view=revision&revision=1907989
http://svn.apache.org/viewvc?view=revision&revision=1908143
http://svn.apache.org/viewvc?view=revision&revision=1908144

--- modules/dav/fs/mod_dav_fs.dsp	(revision 1907973)
+++ modules/dav/fs/mod_dav_fs.dsp	(revision 1907974)
@@ -116,6 +116,10 @@
 # End Source File
 # Begin Source File
 
+SOURCE=.\quota.c
+# End Source File
+# Begin Source File
+
 SOURCE=.\repos.c
 # End Source File
 # End Group
Index: modules/dav/fs/repos.c
===================================================================
