$NetBSD: patch-src_TextAction.c,v 1.2 2022/04/04 12:55:28 wiz Exp $

Fix ctype(3) abuse.
https://gitlab.freedesktop.org/xorg/lib/libxaw/-/merge_requests/11

--- src/TextAction.c.orig	2021-03-27 17:40:21.000000000 +0000
+++ src/TextAction.c
@@ -2607,7 +2607,7 @@ InsertNewLineAndIndent(Widget w, XEvent 
 	strcpy(++ptr, line_to_ip);
 
 	length++;
-	while (length && (isspace(*ptr) || (*ptr == XawTAB)))
+	while (length && (isspace((unsigned char)*ptr) || (*ptr == XawTAB)))
 	    ptr++, length--;
 	*ptr = '\0';
 	text.length = (int)strlen(text.ptr);
@@ -3393,7 +3393,7 @@ Numeric(Widget w, XEvent *event, String 
 	long mult = ctx->text.mult;
 
 	if (*num_params != 1 || strlen(params[0]) != 1
-	    || (!isdigit(params[0][0])
+	    || (!isdigit((unsigned char)params[0][0])
 		&& (params[0][0] != '-' || mult != 0))) {
 	    char err_buf[256];
 
@@ -3591,7 +3591,7 @@ StripOutOldCRs(TextWidget ctx, XawTextPo
 		    if (!iswspace(((wchar_t*)buf)[i]) || ((periodPos + i) >= to))
 			break;
 		}
-		else if (!isspace(buf[i]) || (periodPos + i) >= to)
+		else if (!isspace((unsigned char)buf[i]) || (periodPos + i) >= to)
 		    break;
 
 	    XtFree(buf);
@@ -3681,7 +3681,7 @@ InsertNewCRs(TextWidget ctx, XawTextPosi
 		if (!iswspace(((wchar_t*)buf)[i]))
 		    break;
 	    }
-	    else if (!isspace(buf[i]))
+	    else if (!isspace((unsigned char)buf[i]))
 		break;
 
 	to -= (i - 1);
