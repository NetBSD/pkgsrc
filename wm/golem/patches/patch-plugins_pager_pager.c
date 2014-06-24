$NetBSD: patch-plugins_pager_pager.c,v 1.1 2014/06/24 06:28:02 dholland Exp $

Add some missing error checks. This might fix a segv macallan was seeing.

--- plugins/pager/pager.c~	2001-12-06 04:53:28.000000000 +0000
+++ plugins/pager/pager.c
@@ -457,6 +457,10 @@ int start() {
 		 */
 		if (pager_selpixmap) {
 			image = image_frompixmap(pager_selpixmap, screen);
+			if (!image) {
+				/* XXX I assume this leaks memory */
+				return PLUGIN_UNLOAD;
+			}
 			thisscr->sel_img = image_scale(image,
 				pager_ratio * screen->width,
 				pager_ratio * screen->height);
@@ -464,6 +468,10 @@ int start() {
 		}
 		if (pager_nonselpixmap) {
 			image = image_frompixmap(pager_nonselpixmap, screen);
+			if (!image) {
+				/* XXX I assume this leaks memory */
+				return PLUGIN_UNLOAD;
+			}
 			thisscr->nonsel_img = image_scale(image,
 				pager_ratio * screen->width,
 				pager_ratio * screen->height);
