$NetBSD: patch-Makefile.PL,v 1.1 2014/09/19 05:24:15 schmonz Exp $

Apply 053de54 from upstream git to fix paths in installed binaries
with the default PKG_SYSCONFBASE.

--- Makefile.PL.orig	2014-09-10 07:48:12.000000000 +0000
+++ Makefile.PL
@@ -60,7 +60,7 @@ docwiki:
 	$(PERL) -Iblib/lib $(extramodules) $(tflag) ikiwiki.in -setup docwiki.setup -refresh
 
 sysconfdir:
-	$(PERL) -pi -e "s|/etc/ikiwiki|$(SYSCONFDIR)|g" $(sysconfdir_scripts)
+	$(PERL) -pi -e "s|\"/etc/ikiwiki|\"$(SYSCONFDIR)|g" $(sysconfdir_scripts)
 	
 extra_clean:
 	$(PERL) -Iblib/lib $(extramodules) $(tflag) ikiwiki.in -setup docwiki.setup -clean
