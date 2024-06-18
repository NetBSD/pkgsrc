$NetBSD: patch-mozilla_toolkit_mozapps_installer_packager.mk,v 1.4 2024/06/18 03:17:01 ryoon Exp $

--- toolkit/mozapps/installer/packager.mk.orig	2024-06-17 07:45:27.684803210 +0000
+++ toolkit/mozapps/installer/packager.mk
@@ -129,7 +129,7 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
+	#ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
 
 upload:
 	$(PYTHON3) -u $(MOZILLA_DIR)/build/upload.py --base-path $(DIST) $(UPLOAD_FILES)
