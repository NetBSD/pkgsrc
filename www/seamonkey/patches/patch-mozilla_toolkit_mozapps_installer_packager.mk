$NetBSD: patch-mozilla_toolkit_mozapps_installer_packager.mk,v 1.3 2021/11/30 15:41:24 ryoon Exp $

--- toolkit/mozapps/installer/packager.mk.orig	2021-10-26 16:49:55.000000000 +0000
+++ toolkit/mozapps/installer/packager.mk
@@ -127,7 +127,7 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
+	#ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
 
 upload:
 	$(PYTHON) -u $(MOZILLA_DIR)/build/upload.py --base-path $(DIST) $(UPLOAD_FILES)
