$NetBSD: patch-third__party_vulkan-loader_src_loader_loader__environment.c,v 1.1 2026/07/08 13:42:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/vulkan-loader/src/loader/loader_environment.c.orig	2026-07-06 22:58:46.000000000 +0000
+++ third_party/vulkan-loader/src/loader/loader_environment.c
@@ -264,7 +264,7 @@ VkResult parse_generic_filter_environmen
     }
 
     for (uint32_t iii = 0; iii < env_var_len; ++iii) {
-        parsing_string[iii] = (char)tolower(env_var_value[iii]);
+        parsing_string[iii] = (char)tolower((unsigned char)env_var_value[iii]);
     }
     parsing_string[env_var_len] = '\0';
 
@@ -324,7 +324,7 @@ VkResult parse_layers_disable_filter_env
     }
 
     for (uint32_t iii = 0; iii < env_var_len; ++iii) {
-        parsing_string[iii] = (char)tolower(env_var_value[iii]);
+        parsing_string[iii] = (char)tolower((unsigned char)env_var_value[iii]);
     }
     parsing_string[env_var_len] = '\0';
 
@@ -396,7 +396,7 @@ bool check_name_matches_filter_environme
     const size_t name_len = strlen(name);
     char lower_name[VK_MAX_EXTENSION_NAME_SIZE];
     for (uint32_t iii = 0; iii < name_len; ++iii) {
-        lower_name[iii] = (char)tolower(name[iii]);
+        lower_name[iii] = (char)tolower((unsigned char)name[iii]);
     }
     lower_name[name_len] = '\0';
     for (uint32_t filt = 0; filt < filter_struct->count; ++filt) {
@@ -578,7 +578,7 @@ void parse_id_filter_environment_var(con
     // Allocate a separate string since scan_for_next_comma modifies the original string
     parsing_string = loader_stack_alloc(env_var_len + 1);
     for (uint32_t iii = 0; iii < env_var_len; ++iii) {
-        parsing_string[iii] = (char)tolower(env_var_value[iii]);
+        parsing_string[iii] = (char)tolower((unsigned char)env_var_value[iii]);
     }
     parsing_string[env_var_len] = '\0';
 
