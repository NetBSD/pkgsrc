$NetBSD: patch-Source_autotools_gsettings.m4,v 1.1 2011/12/27 03:54:36 sbd Exp $

${gsettings__base_list} has gsed specific expressions.

--- Source/autotools/gsettings.m4.orig	2011-09-26 20:55:03.000000000 +0000
+++ Source/autotools/gsettings.m4
@@ -46,8 +46,8 @@ install-data-am: install-gsettings-schem
 .SECONDARY: $(gsettings_SCHEMAS)
 
 gsettings__base_list = \
-  sed "$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;s/\n/ /g" | \
-  sed "$$!N;$$!N;$$!N;$$!N;s/\n/ /g"
+  gsed "$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;$$!N;s/\n/ /g" | \
+  gsed "$$!N;$$!N;$$!N;$$!N;s/\n/ /g"
 
 install-gsettings-schemas: $(gsettings_SCHEMAS:.xml=.valid) $(gsettings__enum_file)
 	@$(NORMAL_INSTALL)
