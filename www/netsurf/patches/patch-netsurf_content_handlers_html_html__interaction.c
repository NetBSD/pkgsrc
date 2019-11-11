$NetBSD: patch-netsurf_content_handlers_html_html__interaction.c,v 1.1 2019/11/11 12:58:53 nros Exp $
* fix crash when an entire document has visability: hidden
  from upstream:
http://source.netsurf-browser.org/netsurf.git/commit/content/handlers/html/html_interaction.c?id=acee5faa3f03a229a6d7d14e042441a6af048faf
--- netsurf/content/handlers/html/html_interaction.c.orig	2019-11-11 12:34:12.647371538 +0000
+++ netsurf/content/handlers/html/html_interaction.c
@@ -382,7 +382,7 @@ void html_mouse_action(struct content *c
 	int padding_left, padding_right, padding_top, padding_bottom;
 	browser_drag_type drag_type = browser_window_get_drag_type(bw);
 	union content_msg_data msg_data;
-	struct dom_node *node = NULL;
+	struct dom_node *node = html->layout->node; /* Default to the <HTML> */
 	union html_drag_owner drag_owner;
 	union html_selection_owner sel_owner;
 	bool click = mouse & (BROWSER_MOUSE_PRESS_1 | BROWSER_MOUSE_PRESS_2 |
