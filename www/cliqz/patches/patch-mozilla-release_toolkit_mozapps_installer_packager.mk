$NetBSD: patch-mozilla-release_toolkit_mozapps_installer_packager.mk,v 1.2 2020/04/18 07:58:36 fox Exp $

* Symbolic link to lib/firefox/firefox causes 'Couldn't load XPCOM.' error.
  (taken from www/firefox)

* Disable Normandy client file generation since xpcshell is segfaulting
  since cliqz 1.35.0 (firefox 75.0)

--- mozilla-release/toolkit/mozapps/installer/packager.mk.orig	2020-04-14 16:26:15.000000000 +0000
+++ mozilla-release/toolkit/mozapps/installer/packager.mk
@@ -125,10 +125,10 @@ endif
 
 ifdef MOZ_NORMANDY
 ifndef CROSS_COMPILE
-	# Generate a file that describes the local Normandy client.
-	env LD_LIBRARY_PATH="$(LD_LIBRARY_PATH):$(DIST)/$(PKG_PATH)/bin" \
-		$(DIST)/$(PKG_PATH)/bin/xpcshell \
-		$(MOZILLA_DIR)/toolkit/components/normandy/metadata-script.js $(MOZ_NORMANDY_JSON)
+#	# Generate a file that describes the local Normandy client.
+#	env LD_LIBRARY_PATH="$(LD_LIBRARY_PATH):$(DIST)/$(PKG_PATH)/bin" \
+#		$(DIST)/$(PKG_PATH)/bin/xpcshell \
+#		$(MOZILLA_DIR)/toolkit/components/normandy/metadata-script.js $(MOZ_NORMANDY_JSON)
 endif
 endif
 	$(TOUCH) $@
@@ -155,7 +155,7 @@ endif
 	  (cd $(DESTDIR)$(installdir) && tar -xf -)
 	$(NSINSTALL) -D $(DESTDIR)$(bindir)
 	$(RM) -f $(DESTDIR)$(bindir)/$(MOZ_APP_NAME)
-	ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
+	#ln -s $(installdir)/$(MOZ_APP_NAME) $(DESTDIR)$(bindir)
 
 upload:
 	$(PYTHON3) -u $(MOZILLA_DIR)/build/upload.py --base-path $(DIST) \
