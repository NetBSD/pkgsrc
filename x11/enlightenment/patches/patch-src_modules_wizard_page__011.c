$NetBSD: patch-src_modules_wizard_page__011.c,v 1.1 2013/09/02 11:08:16 obache Exp $

* teach location from pkgsrc.

--- src/modules/wizard/page_011.c.orig	2013-04-04 19:44:46.000000000 +0000
+++ src/modules/wizard/page_011.c
@@ -18,6 +18,9 @@ find_rules(void)
 {
    int i = 0;
    const char *lstfiles[] = {
+#if defined PKGSRC_X11BASE
+      PKGSRC_X11BASE "/share/X11/xkb/rules/base.lst",
+#endif
 #if defined __NetBSD__
       "/usr/X11R7/lib/X11/xkb/rules/xorg.lst",
 #elif defined __OpenBSD__
