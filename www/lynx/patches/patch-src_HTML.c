$NetBSD: patch-src_HTML.c,v 1.1 2018/06/15 22:24:39 tez Exp $

--- src/HTML.c.orig	2018-06-15 21:56:18.188943200 +0000
+++ src/HTML.c
@@ -505,6 +505,8 @@ void HTML_put_character(HTStructured * m
  */
 void HTML_put_string(HTStructured * me, const char *s)
 {
+    HTChunk *target = NULL;
+
 #ifdef USE_PRETTYSRC
     char *translated_string = NULL;
 #endif
@@ -525,15 +527,15 @@ void HTML_put_string(HTStructured * me,
 	break;			/* Do Nothing */
 
     case HTML_TITLE:
-	HTChunkPuts(&me->title, s);
+	target = &me->title;
 	break;
 
     case HTML_STYLE:
-	HTChunkPuts(&me->style_block, s);
+	target = &me->style_block;
 	break;
 
     case HTML_SCRIPT:
-	HTChunkPuts(&me->script, s);
+	target = &me->script;
 	break;
 
     case HTML_PRE:		/* Formatted text */
@@ -547,20 +549,20 @@ void HTML_put_string(HTStructured * me,
 	break;
 
     case HTML_OBJECT:
-	HTChunkPuts(&me->object, s);
+	target = &me->object;
 	break;
 
     case HTML_TEXTAREA:
-	HTChunkPuts(&me->textarea, s);
+	target = &me->textarea;
 	break;
 
     case HTML_SELECT:
     case HTML_OPTION:
-	HTChunkPuts(&me->option, s);
+	target = &me->option;
 	break;
 
     case HTML_MATH:
-	HTChunkPuts(&me->math, s);
+	target = &me->math;
 	break;
 
     default:			/* Free format text? */
@@ -651,6 +653,15 @@ void HTML_put_string(HTStructured * me,
 	    }			/* for */
 	}
     }				/* end switch */
+
+    if (target != NULL) {
+	if (target->data == s) {
+	    CTRACE((tfp, "BUG: appending chunk to itself: `%.*s'\n",
+		    target->size, target->data));
+	} else {
+	    HTChunkPuts(target, s);
+	}
+    }
 #ifdef USE_PRETTYSRC
     if (psrc_convert_string) {
 	psrc_convert_string = FALSE;
