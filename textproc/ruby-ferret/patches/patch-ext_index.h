$NetBSD: patch-ext_index.h,v 1.1 2021/02/14 15:06:43 taca Exp $

* Avoid to use bool.

--- ext/index.h.orig	2021-01-11 06:20:40.416664005 +0000
+++ ext/index.h
@@ -592,7 +592,7 @@ typedef struct FrtLazyDocField
     FrtLazyDoc          *doc;
     int                 size; /* number of data elements */
     int                 len;  /* length of data elements concatenated */
-    bool                is_compressed : 2; /* set to 2 after all data is loaded */
+    int                 is_compressed : 2; /* set to 2 after all data is loaded */
 } FrtLazyDocField;
 
 extern char *frt_lazy_df_get_data(FrtLazyDocField *self, int i);
