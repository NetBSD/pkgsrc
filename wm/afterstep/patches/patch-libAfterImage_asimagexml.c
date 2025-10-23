$NetBSD: patch-libAfterImage_asimagexml.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterImage/asimagexml.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterImage/asimagexml.c
@@ -490,12 +490,12 @@ translate_tag_size(	const char *width_st
 	}
 	if( width_str ) 
 	{	
-		if( width_str[0] == '$' || isdigit( (int)width_str[0] ) )
+		if( width_str[0] == '$' || isdigit( (unsigned char)width_str[0] ) )
 			width = (int)parse_math(width_str, NULL, width);
 	}
 	if( height_str ) 
 	{	
-		if( height_str[0] == '$' || isdigit( (int)height_str[0] ) )
+		if( height_str[0] == '$' || isdigit( (unsigned char)height_str[0] ) )
 			height = (int)parse_math(height_str, NULL, height);
 	}
 	if( width_str && height_ref > 0 && mystrcasecmp(width_str,"proportional") == 0 )
@@ -1329,16 +1329,16 @@ handle_asxml_tag_gradient( ASImageXMLSta
 		} else {
 			gradient.type = GRADIENT_BottomLeft2TopRight;
 		}
-		for (p = color_str ; isspace((int)*p) ; p++);
+		for (p = color_str ; isspace((unsigned char)*p) ; p++);
 		for (npoints1 = 0 ; *p ; npoints1++) {
-			if (*p) for ( ; *p && !isspace((int)*p) ; p++);
-			for ( ; isspace((int)*p) ; p++);
+			if (*p) for ( ; *p && !isspace((unsigned char)*p) ; p++);
+			for ( ; isspace((unsigned char)*p) ; p++);
 		}
 		if (offset_str) {
-			for (p = offset_str ; isspace((int)*p) ; p++);
+			for (p = offset_str ; isspace((unsigned char)*p) ; p++);
 			for (npoints2 = 0 ; *p ; npoints2++) {
-				if (*p) for ( ; *p && !isspace((int)*p) ; p++);
-				for ( ; isspace((int)*p) ; p++);
+				if (*p) for ( ; *p && !isspace((unsigned char)*p) ; p++);
+				for ( ; isspace((unsigned char)*p) ; p++);
 			}
 		}
 		gradient.npoints = max( npoints1, npoints2 );
@@ -1346,11 +1346,11 @@ handle_asxml_tag_gradient( ASImageXMLSta
 			int i;
 			gradient.color = safecalloc(gradient.npoints, sizeof(ARGB32));
 			gradient.offset = NEW_ARRAY(double, gradient.npoints);
-			for (p = color_str ; isspace((int)*p) ; p++);
+			for (p = color_str ; isspace((unsigned char)*p) ; p++);
 			for (npoints1 = 0 ; *p ; ) {
 				char* pb = p, ch;
-				if (*p) for ( ; *p && !isspace((int)*p) ; p++);
-				for ( ; isspace((int)*p) ; p++);
+				if (*p) for ( ; *p && !isspace((unsigned char)*p) ; p++);
+				for ( ; isspace((unsigned char)*p) ; p++);
 				ch = *p; *p = '\0';
 				if (parse_argb_color(pb, gradient.color + npoints1) != pb)
 				{
@@ -1360,15 +1360,15 @@ handle_asxml_tag_gradient( ASImageXMLSta
 				*p = ch;
 			}
 			if (offset_str) {
-				for (p = offset_str ; isspace((int)*p) ; p++);
+				for (p = offset_str ; isspace((unsigned char)*p) ; p++);
 				for (npoints2 = 0 ; *p ; ) {
 					char* pb = p, ch;
-					if (*p) for ( ; *p && !isspace((int)*p) ; p++);
+					if (*p) for ( ; *p && !isspace((unsigned char)*p) ; p++);
 					ch = *p; *p = '\0';
 					gradient.offset[npoints2] = strtod(pb, &pb);
 					if (pb == p) npoints2++;
 					*p = ch;
-					for ( ; isspace((int)*p) ; p++);
+					for ( ; isspace((unsigned char)*p) ; p++);
 				}
 			} else {
 				for (npoints2 = 0 ; npoints2 < gradient.npoints ; npoints2++)
@@ -1690,9 +1690,9 @@ handle_asxml_tag_bevel( ASImageXMLState 
 			bevel.top_inline = bevel.left_inline = bevel.right_inline = bevel.bottom_inline = 10;
 		if (color_str) {
 			char* p = color_str;
-			while (isspace((int)*p)) p++;
+			while (isspace((unsigned char)*p)) p++;
 			p = (char*)parse_argb_color(p, &bevel.hi_color);
-			while (isspace((int)*p)) p++;
+			while (isspace((unsigned char)*p)) p++;
 			parse_argb_color(p, &bevel.lo_color);
 		}
 		if (border_str) {
@@ -2230,7 +2230,7 @@ handle_asxml_tag_hsv( ASImageXMLState *s
 		else if (!strcmp(ptr->tag, "y_origin")) yorig = (int)parse_math(ptr->parm, NULL, height);
 		else if (!strcmp(ptr->tag, "affected_hue"))
 		{
-			if( isdigit( (int)ptr->parm[0] ) )
+			if( isdigit( (unsigned char)ptr->parm[0] ) )
 				affected_hue = (int)parse_math(ptr->parm, NULL, 360);
 			else
 			{
