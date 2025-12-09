$NetBSD: patch-amdgpu_amdgpu__asic__id.c,v 1.1 2025/12/09 11:41:35 wiz Exp $

Fix build on NetBSD.
https://gitlab.freedesktop.org/mesa/libdrm/-/merge_requests/444

--- amdgpu/amdgpu_asic_id.c.orig	2025-12-08 13:15:17.000000000 +0000
+++ amdgpu/amdgpu_asic_id.c
@@ -23,9 +23,11 @@
  */
 
 // secure_getenv requires _GNU_SOURCE
+#if HAVE_SECURE_GETENV
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
 #endif
+#endif
 
 #include <ctype.h>
 #include <stdio.h>
@@ -165,6 +167,7 @@ static void amdgpu_parse_proc_cpuinfo(st
 	fclose(fp);
 }
 
+#if HAVE_SECURE_GETENV
 static char *join_path(const char *dir, const char *file) {
 	size_t dir_len = strlen(dir);
 	size_t file_len = strlen(file);
@@ -268,6 +271,7 @@ static char *find_asic_id_table(void)
 	split_env_var_free(paths);
 	return found_path;
 }
+#endif
 
 void amdgpu_parse_asic_ids(struct amdgpu_device *dev)
 {
@@ -278,11 +282,17 @@ void amdgpu_parse_asic_ids(struct amdgpu
 	int line_num = 1;
 	int r = 0;
 
+#if HAVE_SECURE_GETENV
 	char *amdgpu_asic_id_table_path = find_asic_id_table();
 
 	// if not found, use the default AMDGPU_ASIC_ID_TABLE path
 	if (!amdgpu_asic_id_table_path)
 		amdgpu_asic_id_table_path = strdup(AMDGPU_ASIC_ID_TABLE);
+#else
+	// if this system lacks secure_getenv(), don't allow extra paths
+	// for security reasons.
+	char *amdgpu_asic_id_table_path = strdup(AMDGPU_ASIC_ID_TABLE);
+#endif
 
 	fp = fopen(amdgpu_asic_id_table_path, "r");
 	if (!fp) {
