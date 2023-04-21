$NetBSD: patch-rfc4331quotas-modules_dav_fs_mod_dav_fs.mak,v 1.1 2023/04/21 13:52:33 manu Exp $

RFC4331 quotas from upstream trunk
http://svn.apache.org/viewvc?view=revision&revision=1907974
http://svn.apache.org/viewvc?view=revision&revision=1907984
http://svn.apache.org/viewvc?view=revision&revision=1907989
http://svn.apache.org/viewvc?view=revision&revision=1908143
http://svn.apache.org/viewvc?view=revision&revision=1908144

--- modules/dav/fs/mod_dav_fs.mak.orig
+++ modules/dav/fs/mod_dav_fs.mak
@@ -54,8 +54,9 @@
 	-@erase "$(INTDIR)\mod_dav_fs.obj"
 	-@erase "$(INTDIR)\mod_dav_fs.res"
 	-@erase "$(INTDIR)\mod_dav_fs_src.idb"
 	-@erase "$(INTDIR)\mod_dav_fs_src.pdb"
+	-@erase "$(INTDIR)\quota.obj"
 	-@erase "$(INTDIR)\repos.obj"
 	-@erase "$(OUTDIR)\mod_dav_fs.exp"
 	-@erase "$(OUTDIR)\mod_dav_fs.lib"
 	-@erase "$(OUTDIR)\mod_dav_fs.pdb"
@@ -110,8 +111,9 @@
 LINK32_OBJS= \
 	"$(INTDIR)\dbm.obj" \
 	"$(INTDIR)\lock.obj" \
 	"$(INTDIR)\mod_dav_fs.obj" \
+	"$(INTDIR)\quota.obj" \
 	"$(INTDIR)\repos.obj" \
 	"$(INTDIR)\mod_dav_fs.res" \
 	"..\..\..\srclib\apr\Release\libapr-1.lib" \
 	"..\..\..\srclib\apr-util\Release\libaprutil-1.lib" \
@@ -165,8 +167,9 @@
 	-@erase "$(INTDIR)\mod_dav_fs.obj"
 	-@erase "$(INTDIR)\mod_dav_fs.res"
 	-@erase "$(INTDIR)\mod_dav_fs_src.idb"
 	-@erase "$(INTDIR)\mod_dav_fs_src.pdb"
+	-@erase "$(INTDIR)\quota.obj"
 	-@erase "$(INTDIR)\repos.obj"
 	-@erase "$(OUTDIR)\mod_dav_fs.exp"
 	-@erase "$(OUTDIR)\mod_dav_fs.lib"
 	-@erase "$(OUTDIR)\mod_dav_fs.pdb"
@@ -221,8 +224,9 @@
 LINK32_OBJS= \
 	"$(INTDIR)\dbm.obj" \
 	"$(INTDIR)\lock.obj" \
 	"$(INTDIR)\mod_dav_fs.obj" \
+	"$(INTDIR)\quota.obj" \
 	"$(INTDIR)\repos.obj" \
 	"$(INTDIR)\mod_dav_fs.res" \
 	"..\..\..\srclib\apr\Debug\libapr-1.lib" \
 	"..\..\..\srclib\apr-util\Debug\libaprutil-1.lib" \
@@ -274,8 +278,13 @@
 
 "$(INTDIR)\mod_dav_fs.obj" : $(SOURCE) "$(INTDIR)"
 
 
+SOURCE=.\quota.c
+
+"$(INTDIR)\quota.obj" : $(SOURCE) "$(INTDIR)"
+
+
 SOURCE=.\repos.c
 
 "$(INTDIR)\repos.obj" : $(SOURCE) "$(INTDIR)"
 
