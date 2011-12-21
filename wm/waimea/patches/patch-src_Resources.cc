$NetBSD: patch-src_Resources.cc,v 1.1 2011/12/21 13:02:10 wiz Exp $

Avoid conflict with list<>.

--- src/Resources.cc.orig	2002-11-06 11:55:10.000000000 +0000
+++ src/Resources.cc
@@ -1568,7 +1568,7 @@ void ResourceHandler::LoadActions(WaScre
                                                            NULL);
                             str = str + i3 + 1;
                             ReadActions((char *) buffer2, defs, &wacts,
-                                        &ext_list->list, wascreen);
+                                        &ext_list->rlist, wascreen);
                         }
                         else if (str[0] == 'n' && str[1] == '/') {
                             for (i3 = 2; str[i3] != '\0' &&
@@ -1583,7 +1583,7 @@ void ResourceHandler::LoadActions(WaScre
                                                            NULL);
                             str = str + i3 + 1;
                             ReadActions((char *) buffer2, defs, &wacts,
-                                        &ext_list->list, wascreen);
+                                        &ext_list->rlist, wascreen);
                         }
                         else if (str[0] == 't' && str[1] == '/') {
                             for (i3 = 2; str[i3] != '\0' &&
@@ -1598,7 +1598,7 @@ void ResourceHandler::LoadActions(WaScre
                                                            str + 2);
                             str = str + i3 + 1;
                             ReadActions((char *) buffer2, defs, &wacts,
-                                        &ext_list->list, wascreen);
+                                        &ext_list->rlist, wascreen);
                         }
                         else if (! strncasecmp(str, "window", 6)) {
                             str = str + 6;
