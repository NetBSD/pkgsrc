$NetBSD: patch-src_mksary.c,v 1.1 2018/06/29 17:01:16 taca Exp $

* Avoid name confliction.
* Avoid using deprecated function.

--- src/mksary.c.orig	2004-06-11 18:57:28.000000000 +0000
+++ src/mksary.c
@@ -59,10 +59,10 @@ CodesetFunc codeset_func_tab[] = {
 static SaryIpointFunc	dispatch_codeset_func	(const gchar *codeset);
 static SaryBuilder*	new_builder		(const gchar *file_name, 
 						 const gchar *array_name);
-static void		index			(SaryBuilder *builder,
+static void		sary_index		(SaryBuilder *builder,
 						 const gchar *file_name,
 						 const gchar *array_name);
-static void		sort			(SaryBuilder *builder,
+static void		sary_sort		(SaryBuilder *builder,
 						 const gchar *file_name,
 						 const gchar *array_name);
 static void		index_and_sort		(SaryBuilder *builder,
@@ -121,7 +121,7 @@ dispatch_codeset_func (const gchar *code
     CodesetFunc *cursor;
 
     for (cursor = codeset_func_tab; cursor->codeset != NULL; cursor++) {
-	if (g_strcasecmp(cursor->codeset, codeset) == 0) {
+	if (g_ascii_strcasecmp(cursor->codeset, codeset) == 0) {
 	    return cursor->ipoint_func;
 	}
     }
@@ -149,7 +149,7 @@ new_builder (const gchar *file_name, con
 }
 
 static void
-index (SaryBuilder *builder,
+sary_index (SaryBuilder *builder,
        const gchar *file_name, 
        const gchar *array_name)
 {
@@ -165,7 +165,7 @@ index (SaryBuilder *builder,
 
 
 static void
-sort (SaryBuilder *builder,
+sary_sort (SaryBuilder *builder,
       const gchar *file_name, 
       const gchar *array_name)
 {
@@ -186,8 +186,8 @@ index_and_sort (SaryBuilder *builder,
 		const gchar *file_name, 
 		const gchar *array_name)
 {
-    index(builder, file_name, array_name);
-    sort(builder, file_name, array_name);
+    sary_index(builder, file_name, array_name);
+    sary_sort(builder, file_name, array_name);
 }
 
 static void
@@ -358,7 +358,7 @@ parse_options (int argc, char **argv)
 	    show_help();
 	    break;
 	case 'i':
-	    process = index;
+	    process = sary_index;
 	    break;
 	case 'l':
 	    ipoint_func = sary_ipoint_line;
@@ -373,7 +373,7 @@ parse_options (int argc, char **argv)
 	    progress_func = progress_quiet;
 	    break;
 	case 's':
-	    process = sort;
+	    process = sary_sort;
 	    break;
 	case 't':
 	    if (optarg) {
