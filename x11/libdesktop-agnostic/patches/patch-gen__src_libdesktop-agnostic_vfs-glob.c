$NetBSD: patch-gen__src_libdesktop-agnostic_vfs-glob.c,v 1.1.1.1 2012/02/19 14:23:00 imil Exp $

--- gen_src/libdesktop-agnostic/vfs-glob.c.orig	2011-03-13 18:30:12.000000000 +0000
+++ gen_src/libdesktop-agnostic/vfs-glob.c
@@ -365,7 +365,7 @@ static void desktop_agnostic_vfs_glob_cl
 
 static void desktop_agnostic_vfs_glob_instance_init (DesktopAgnosticVFSGlob * self) {
 	self->priv = DESKTOP_AGNOSTIC_VFS_GLOB_GET_PRIVATE (self);
-	self->priv->_flags = (GLOB_MARK | GLOB_BRACE) | GLOB_TILDE_CHECK;
+	self->priv->_flags = (GLOB_MARK | GLOB_BRACE) | GLOB_TILDE;
 }
 
 
