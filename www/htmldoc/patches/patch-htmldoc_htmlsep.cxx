$NetBSD: patch-htmldoc_htmlsep.cxx,v 1.1 2016/12/17 14:20:14 joerg Exp $

Don't check the pointer, but the pointed to value.

--- htmldoc/htmlsep.cxx.orig	2016-12-17 10:25:12.905636738 +0000
+++ htmldoc/htmlsep.cxx
@@ -536,7 +536,7 @@ write_doc(FILE   **out,			// I - Output 
     if (t->markup >= MARKUP_H1 && t->markup < (MARKUP_H1 + TocLevels) &&
         htmlGetVariable(t, (uchar *)"_HD_OMIT_TOC") == NULL)
     {
-      if (heading >= 0)
+      if (*heading >= 0)
         write_footer(out, *heading);
 
       (*heading) ++;
