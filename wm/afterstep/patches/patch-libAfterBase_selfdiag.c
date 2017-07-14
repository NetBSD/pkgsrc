$NetBSD: patch-libAfterBase_selfdiag.c,v 1.1 2017/07/14 12:52:49 joerg Exp $

Provide something at least sensible, even though the function seems to be
unused.

--- libAfterBase/selfdiag.c.orig	2017-07-12 21:29:50.328824882 +0000
+++ libAfterBase/selfdiag.c
@@ -52,6 +52,9 @@
 
 #ifdef HAVE_ELF_H
 # include <elf.h>
+# ifdef __NetBSD__
+# include <dlfcn.h>
+# endif
 #endif
 
 #include <signal.h>
@@ -97,6 +100,13 @@ get_proc_tables (proc_tables * ptabs)
 # if (defined(HAVE_ELF32_DYN_D_TAG) || defined(HAVE_ELF64_DYN_D_TAG)) && HAVE_DECL_ELFW
 	ElfW (Dyn) * dyn;
 
+# ifdef __NetBSD__
+	const struct link_map *map;
+	if (dlinfo(RTLD_SELF, RTLD_DI_LINKMAP, &map))
+		return;
+	void *_DYNAMIC = map->l_ld;
+#endif
+
 	memset (ptabs, 0x00, sizeof (proc_tables));
 	for (dyn = _DYNAMIC; dyn != NULL && dyn->d_tag != DT_NULL; ++dyn)
 		switch (dyn->d_tag)
