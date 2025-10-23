$NetBSD: patch-src_afterstep_dirtree.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/afterstep/dirtree.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/dirtree.c
@@ -407,10 +407,10 @@ LOCAL_DEBUG_OUT ("Parsing \"%s\"", file)
 			if (*ptr == '_')
 				++ptr;
 			if (!mystrncasecmp (ptr, "ordered", 7)) {
-				for (ptr += 7; isspace (*ptr); ptr++) ;
-				if (isdigit (*ptr)) {
+				for (ptr += 7; isspace ((unsigned char)*ptr); ptr++) ;
+				if (isdigit ((unsigned char)*ptr)) {
 					include_order = atoi (ptr);
-					while (isdigit (*ptr))
+					while (isdigit ((unsigned char)*ptr))
 						++ptr;
 				}
 			}
@@ -420,14 +420,14 @@ LOCAL_DEBUG_OUT ("Parsing \"%s\"", file)
 			char *path;
 			dirtree_t *t;
 
-			while (isspace (*ptr))
+			while (isspace ((unsigned char)*ptr))
 				ptr++;
 			if (*ptr != '"')
 				continue;
 			path = ++ptr;
 			for (; *ptr != '\0' && *ptr != '"'; ptr++) ;
 			if (*ptr == '"')
-				for (*ptr++ = '\0'; isspace (*ptr); ptr++) ;
+				for (*ptr++ = '\0'; isspace ((unsigned char)*ptr); ptr++) ;
 			path = make_absolute (tree->path, path);
 			t = dirtree_new_from_dir (path);
 			free (path);
@@ -452,8 +452,8 @@ LOCAL_DEBUG_OUT ("Parsing \"%s\"", file)
 		else if (!mystrncasecmp (ptr, "extension", 9)) {
 			char *tmp;
 
-			for (ptr += 9; isspace (*ptr); ptr++) ;
-			for (tmp = ptr + strlen (ptr); tmp > ptr && isspace (*(tmp - 1));
+			for (ptr += 9; isspace ((unsigned char)*ptr); ptr++) ;
+			for (tmp = ptr + strlen (ptr); tmp > ptr && isspace ((unsigned char)*(tmp - 1));
 					 tmp--) ;
 			if (tmp != ptr) {
 				if (tree->extension)
@@ -463,8 +463,8 @@ LOCAL_DEBUG_OUT ("Parsing \"%s\"", file)
 		} else if (!mystrncasecmp (ptr, "miniextension", 13)) {
 			char *tmp;
 
-			for (ptr += 13; isspace (*ptr); ptr++) ;
-			for (tmp = ptr + strlen (ptr); tmp > ptr && isspace (*(tmp - 1));
+			for (ptr += 13; isspace ((unsigned char)*ptr); ptr++) ;
+			for (tmp = ptr + strlen (ptr); tmp > ptr && isspace ((unsigned char)*(tmp - 1));
 					 tmp--) ;
 			if (tmp != ptr)
 				tree->minipixmap_extension = mystrndup (ptr, tmp - ptr);
@@ -478,7 +478,7 @@ LOCAL_DEBUG_OUT ("Parsing \"%s\"", file)
 			set_string (&(tree->icon), stripcpy2 (ptr + 10, False));
 
 		} else if (!mystrncasecmp (ptr, "command", 7)) {
-			for (ptr += 7; isspace (*ptr); ptr++) ;
+			for (ptr += 7; isspace ((unsigned char)*ptr); ptr++) ;
 			txt2func (ptr, &tree->command, False);
 			dirtree_set_command (tree, &tree->command, 0);
 		} else if (!mystrncasecmp (ptr, "order", 5)) {
@@ -744,7 +744,7 @@ void dirtree_output_tree (FILE * fp, dir
 				struct config *config = find_config (func_config, buf);
 				char *ptr = strip_whitespace (buf);
 
-				if (config != NULL && !isspace (buf[strlen (config->keyword)]))
+				if (config != NULL && !isspace ((unsigned char)buf[strlen (config->keyword)]))
 					config = NULL;
 				if (config == NULL && 13 + strlen (t->name) + strlen (ptr) < 8192) {
 					memmove (ptr + 13 + strlen (t->name), ptr, strlen (ptr) + 1);
@@ -755,11 +755,11 @@ void dirtree_output_tree (FILE * fp, dir
 #ifndef NO_AVAILABILITYCHECK
 					char *tmp;
 
-					for (tmp = ptr + 4; isspace (*tmp); tmp++) ;
+					for (tmp = ptr + 4; isspace ((unsigned char)*tmp); tmp++) ;
 					if (*tmp == '"') {
 						for (tmp++; *tmp != '\0' && *tmp != '"'; tmp++) ;
 						if (*tmp == '"') {
-							for (tmp++; isspace (*tmp); tmp++) ;
+							for (tmp++; isspace ((unsigned char)*tmp); tmp++) ;
 							if (!is_executable_in_path (tmp)) {
 								if (config != NULL)
 									memcpy (ptr, "Nop ", 4);
