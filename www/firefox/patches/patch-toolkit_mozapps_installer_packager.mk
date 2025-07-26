$NetBSD: patch-toolkit_mozapps_installer_packager.mk,v 1.4 2025/07/26 14:12:54 ryoon Exp $

* Symbolic link to lib/firefox/firefox causes 'Couldn't load XPCOM.' error.

--- toolkit/mozapps/installer/packager.mk.orig	2025-07-17 18:03:38.000000000 +0000
+++ toolkit/mozapps/installer/packager.mk
@@ -169,7 +169,7 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
+	#ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
 
 upload:
 	$(PYTHON3) -u $(MOZILLA_DIR)/build/upload.py --base-path $(ABS_DIST) $(UPLOAD_FILES)
