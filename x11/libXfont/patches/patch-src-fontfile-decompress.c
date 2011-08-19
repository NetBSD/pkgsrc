$NetBSD: patch-src-fontfile-decompress.c,v 1.1.2.2 2011/08/19 08:18:32 sbd Exp $

Fix buffer overflow in LZW handler.

--- src/fontfile/decompress.c.orig	2010-06-23 11:18:18.000000000 +0000
+++ src/fontfile/decompress.c
@@ -99,7 +99,7 @@ static char_type magic_header[] = { "\03
 #define FIRST	257	/* first free entry */
 #define	CLEAR	256	/* table clear output code */
 
-#define STACK_SIZE  8192
+#define STACK_SIZE  65300
 
 typedef struct _compressedFILE {
     BufFilePtr	    file;
@@ -180,14 +180,12 @@ BufFilePushCompressed (BufFilePtr f)
 	file->tab_suffix[code] = (char_type) code;
     }
     file->free_ent = ((file->block_compress) ? FIRST : 256 );
+    file->oldcode = -1;
     file->clear_flg = 0;
     file->offset = 0;
     file->size = 0;
     file->stackp = file->de_stack;
     bzero(file->buf, BITS);
-    file->finchar = file->oldcode = getcode (file);
-    if (file->oldcode != -1)
-	*file->stackp++ = file->finchar;
     return BufFileCreate ((char *) file,
 			  BufCompressedFill,
 			  0,
@@ -232,9 +230,6 @@ BufCompressedFill (BufFilePtr f)
 	if (buf == bufend)
 	    break;
 
-	if (oldcode == -1)
-	    break;
-
 	code = getcode (file);
 	if (code == -1)
 	    break;
@@ -243,19 +238,29 @@ BufCompressedFill (BufFilePtr f)
 	    for ( code = 255; code >= 0; code-- )
 	    	file->tab_prefix[code] = 0;
 	    file->clear_flg = 1;
-	    file->free_ent = FIRST - 1;
-	    if ( (code = getcode (file)) == -1 )	/* O, untimely death! */
-	    	break;
+	    file->free_ent = FIRST;
+	    oldcode = -1;
+	    continue;
     	}
     	incode = code;
     	/*
      	 * Special case for KwKwK string.
      	 */
     	if ( code >= file->free_ent ) {
+	    if ( code > file->free_ent || oldcode == -1 ) {
+		/* Bad stream. */
+		return BUFFILEEOF;
+	    }
 	    *stackp++ = finchar;
 	    code = oldcode;
     	}
-    
+	/*
+	 * The above condition ensures that code < free_ent.
+	 * The construction of tab_prefixof in turn guarantees that
+	 * each iteration decreases code and therefore stack usage is
+	 * bound by 1 << BITS - 256.
+	 */
+
     	/*
      	 * Generate output characters in reverse order
      	 */
@@ -270,7 +275,7 @@ BufCompressedFill (BufFilePtr f)
     	/*
      	 * Generate the new entry.
      	 */
-    	if ( (code=file->free_ent) < file->maxmaxcode ) {
+    	if ( (code=file->free_ent) < file->maxmaxcode && oldcode != -1) {
 	    file->tab_prefix[code] = (unsigned short)oldcode;
 	    file->tab_suffix[code] = finchar;
 	    file->free_ent = code+1;
