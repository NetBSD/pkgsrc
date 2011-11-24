$NetBSD: patch-common_gdm-config.h,v 1.1 2011/11/24 13:31:30 joerg Exp $

--- common/gdm-config.h.orig	2011-11-24 00:34:23.000000000 +0000
+++ common/gdm-config.h
@@ -157,7 +157,7 @@ gboolean               gdm_config_get_st
 							  char           **str);
 gboolean               gdm_config_get_bool_for_id        (GdmConfig       *config,
 							  int              id,
-							  gboolean        *bool);
+							  gboolean        *not_bool);
 gboolean               gdm_config_get_int_for_id         (GdmConfig       *config,
 							  int              id,
 							  int             *integer);
@@ -166,7 +166,7 @@ gboolean               gdm_config_set_st
 							  char            *str);
 gboolean               gdm_config_set_bool_for_id        (GdmConfig       *config,
 							  int              id,
-							  gboolean         bool);
+							  gboolean         not_bool);
 gboolean               gdm_config_set_int_for_id         (GdmConfig       *config,
 							  int              id,
 							  int              integer);
@@ -201,7 +201,7 @@ void                 gdm_config_value_se
 void                 gdm_config_value_set_int          (GdmConfigValue  *value,
 							int              integer);
 void                 gdm_config_value_set_bool         (GdmConfigValue  *value,
-							gboolean         bool);
+							gboolean         not_bool);
 char *               gdm_config_value_to_string        (const GdmConfigValue *value);
 
 /* Config Entries */
