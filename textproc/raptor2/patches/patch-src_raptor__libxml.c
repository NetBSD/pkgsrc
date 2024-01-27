$NetBSD: patch-src_raptor__libxml.c,v 1.1 2024/01/27 15:32:19 wiz Exp $

Fix build with libxml 2.12.
https://github.com/dajobe/raptor/commit/4dbc4c1da2a033c497d84a1291c46f416a9cac51

--- src/raptor_libxml.c.orig	2024-01-27 15:31:31.774167018 +0000
+++ src/raptor_libxml.c
@@ -246,7 +246,7 @@ raptor_libxml_getEntity(void* user_data,
     
     ret->owner = 1;
 
-#if LIBXML_VERSION >= 20627
+#if LIBXML_VERSION >= 20627 && LIBXML_VERSION < 21100
     /* Checked field was released in 2.6.27 on 2006-10-25
      * http://git.gnome.org/browse/libxml2/commit/?id=a37a6ad91a61d168ecc4b29263def3363fff4da6
      *
