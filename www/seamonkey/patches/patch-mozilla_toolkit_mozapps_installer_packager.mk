$NetBSD: patch-mozilla_toolkit_mozapps_installer_packager.mk,v 1.1 2020/05/06 14:34:53 ryoon Exp $

--- mozilla/toolkit/mozapps/installer/packager.mk.orig	2020-02-17 23:39:43.000000000 +0000
+++ mozilla/toolkit/mozapps/installer/packager.mk
@@ -125,7 +125,7 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
+	#ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
 
 checksum:
 	mkdir -p `dirname $(CHECKSUM_FILE)`
