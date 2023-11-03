$NetBSD: patch-spectrwm.c,v 1.3 2023/11/03 08:14:10 pin Exp $

Fix NetBSD build issues.
See commit 624b67f32723ab600cbc272e9199cadd66659825

--- spectrwm.c.orig	2023-10-22 07:58:36.000000000 +0000
+++ spectrwm.c
@@ -63,6 +63,9 @@
 #else
 #include <util.h>
 #endif
+#if defined(__NetBSD__)
+#include <inttypes.h>
+#endif
 #include <X11/cursorfont.h>
 #include <X11/extensions/Xrandr.h>
 #include <X11/Xcursor/Xcursor.h>
@@ -74,7 +77,8 @@
 #include <xcb/xcb_event.h>
 #include <xcb/xcb_icccm.h>
 #include <xcb/xcb_keysyms.h>
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) ||	\
+    defined(__NetBSD__)
 #include <xcb/xinput.h>
 #define SWM_XCB_HAS_XINPUT
 #endif
@@ -1713,6 +1717,7 @@ void	 stack_master(struct workspace *, s
 static void	 update_layout(struct swm_screen *);
 void	 store_float_geom(struct ws_win *);
 char	*strdupsafe(const char *);
+static int32_t	 strtoint32(const char *, int32_t, int32_t, int *);
 void	 swapwin(struct swm_screen *, struct binding *, union arg *);
 void	 switch_workspace(struct swm_region *, struct workspace *, bool);
 void	 switchlayout(struct swm_screen *, struct binding *, union arg *);
@@ -5188,7 +5193,7 @@ bar_setup(struct swm_region *r)
 
 	r->bar->r = r;
 	X(r->bar) = X(r) + bar_border_width;
-	Y(r->bar) = bar_at_bottom ? (Y(r) + HEIGHT(r) - bar_height -
+	Y(r->bar) = bar_at_bottom ? (Y(r) + HEIGHT(r) - bar_height +
 	    bar_border_width) : Y(r) + bar_border_width;
 	WIDTH(r->bar) = WIDTH(r) - 2 * bar_border_width;
 	HEIGHT(r->bar) = bar_height - 2 * bar_border_width;
@@ -8725,7 +8730,7 @@ get_win_name(xcb_window_t win)
 		name = strdup("");
 
 	if (name == NULL)
-		err(1, "get_win_name: failed to allocate memory.");
+		err(1, "get_win_name: strdup");
 
 	free(r);
 
@@ -9323,8 +9328,7 @@ search_resp_search_workspace(const char 
 {
 	struct workspace	*ws;
 	char			*p, *q;
-	int			ws_idx;
-	const char		*errstr;
+	int			ws_idx, fail;
 
 	DNPRINTF(SWM_D_MISC, "resp: %s\n", resp);
 
@@ -9336,9 +9340,9 @@ search_resp_search_workspace(const char 
 	p = strchr(q, ':');
 	if (p != NULL)
 		*p = '\0';
-	ws_idx = (int)strtonum(q, 1, workspace_limit, &errstr) - 1;
-	if (errstr) {
-		DNPRINTF(SWM_D_MISC, "workspace idx is %s: %s", errstr, q);
+	ws_idx = strtoint32(q, 1, workspace_limit, &fail) - 1;
+	if (fail) {
+		DNPRINTF(SWM_D_MISC, "integer conversion failed for %s\n", q);
 		free(q);
 		return;
 	}
@@ -9353,8 +9357,7 @@ void
 search_resp_search_window(const char *resp)
 {
 	char			*s, *p;
-	int			idx;
-	const char		*errstr;
+	int			idx, fail;
 	struct search_window	*sw;
 
 	DNPRINTF(SWM_D_MISC, "resp: %s\n", resp);
@@ -9367,9 +9370,9 @@ search_resp_search_window(const char *re
 	p = strchr(s, ':');
 	if (p != NULL)
 		*p = '\0';
-	idx = (int)strtonum(s, 1, INT_MAX, &errstr);
-	if (errstr) {
-		DNPRINTF(SWM_D_MISC, "window idx is %s: %s", errstr, s);
+	idx = strtoint32(s, 1, INT_MAX, &fail);
+	if (fail) {
+		DNPRINTF(SWM_D_MISC, "integer conversion failed for %s\n", s);
 		free(s);
 		return;
 	}
@@ -12046,6 +12049,7 @@ get_input_event_label(xcb_ge_generic_eve
 
 	return (label);
 }
+#endif /* SWM_XCB_HAS_XINPUT */
 
 #if defined(SWM_XCB_HAS_XINPUT) && defined(XCB_INPUT_RAW_BUTTON_PRESS)
 void
@@ -13153,7 +13157,7 @@ setconfcolorlist(const char *selector, c
 
 		num_bg_colors = 0;
 		while ((b = strsep(&sp, SWM_CONF_DELIMLIST)) != NULL) {
-			while (isblank(*b)) b++;
+			while (isblank((unsigned char)*b)) b++;
 			if (*b == '\0')
 				continue;
 			setconfcolor(selector, b, flags + num_bg_colors, emsg);
@@ -13171,7 +13175,7 @@ setconfcolorlist(const char *selector, c
 
 		num_fg_colors = 0;
 		while ((b = strsep(&sp, SWM_CONF_DELIMLIST)) != NULL) {
-			while (isblank(*b)) b++;
+			while (isblank((unsigned char)*b)) b++;
 			if (*b == '\0')
 				continue;
 			setconfcolor(selector, b, flags + num_fg_colors, emsg);
@@ -13662,7 +13666,7 @@ conf_load(const char *filename, int keym
 		}
 		/* trim trailing spaces */
 		ce = optval + strlen(optval) - 1;
-		while (ce > optval && isspace(*ce))
+		while (ce > optval && isspace((unsigned char)*ce))
 			--ce;
 		*(ce + 1) = '\0';
 		/* call function to deal with it all */
@@ -13687,85 +13691,69 @@ conf_load(const char *filename, int keym
 	return (0);
 }
 
+static int32_t
+strtoint32(const char *str, int32_t min, int32_t max, int *fail)
+{
+	int32_t		ret;
+#if defined(__NetBSD__)
+	int		e;
+
+	ret = strtoi(str, NULL, 10, min, max, &e);
+	*fail = (e != 0);
+#else
+	const char	*errstr;
+
+	ret = strtonum(str, min, max, &errstr);
+	*fail = (errstr != NULL);
+#endif
+	return (ret);
+}
+
 pid_t
 window_get_pid(xcb_window_t win)
 {
 	pid_t				ret = 0;
-	const char			*errstr;
-	xcb_get_property_cookie_t	pc;
+	int				fail;
 	xcb_get_property_reply_t	*pr;
 
-	pc = xcb_get_property(conn, 0, win, a_net_wm_pid,
-	    XCB_ATOM_CARDINAL, 0, 1);
-	pr = xcb_get_property_reply(conn, pc, NULL);
-	if (pr == NULL)
-		goto tryharder;
-	if (pr->type != XCB_ATOM_CARDINAL) {
-		free(pr);
-		goto tryharder;
-	}
-
-	if (pr->type == a_net_wm_pid && pr->format == 32)
+	pr = xcb_get_property_reply(conn, xcb_get_property(conn, 0, win,
+	    a_net_wm_pid, XCB_ATOM_CARDINAL, 0, 1), NULL);
+	if (pr && pr->type == XCB_ATOM_CARDINAL && pr->format == 32)
 		ret = *((pid_t *)xcb_get_property_value(pr));
-	free(pr);
-
-	return (ret);
-
-tryharder:
-	pc = xcb_get_property(conn, 0, win, a_swm_pid, XCB_ATOM_STRING,
-	    0, SWM_PROPLEN);
-	pr = xcb_get_property_reply(conn, pc, NULL);
-	if (pr == NULL)
-		return (0);
-	if (pr->type != a_swm_pid) {
+	else { /* tryharder */
 		free(pr);
-		return (0);
+		pr = xcb_get_property_reply(conn, xcb_get_property(conn, 0, win,
+		    a_swm_pid, XCB_ATOM_STRING, 0, SWM_PROPLEN), NULL);
+		if (pr && pr->type == XCB_ATOM_STRING && pr->format == 8) {
+			ret = (pid_t)strtoint32(xcb_get_property_value(pr), 0,
+			    INT32_MAX, &fail);
+			if (fail)
+				ret = 0;
+		}
 	}
-
-	ret = (pid_t)strtonum(xcb_get_property_value(pr), 0, INT_MAX, &errstr);
 	free(pr);
 
+	DNPRINTF(SWM_D_PROP, "pid: %d\n", ret);
 	return (ret);
 }
 
 int
 get_swm_ws(xcb_window_t id)
 {
-	int			ws_idx = -2;
-	char			*prop = NULL;
-	size_t			proplen;
-	const char		*errstr;
+	int				ws_idx = -2, fail;
 	xcb_get_property_reply_t	*gpr;
 
-	gpr = xcb_get_property_reply(conn,
-		xcb_get_property(conn, 0, id, a_swm_ws,
-		    XCB_ATOM_STRING, 0, SWM_PROPLEN),
-		NULL);
-	if (gpr == NULL)
-		return (-1);
-	if (gpr->type) {
-		proplen = xcb_get_property_value_length(gpr);
-		if (proplen > 0) {
-			prop = malloc(proplen + 1);
-			if (prop) {
-				memcpy(prop,
-				    xcb_get_property_value(gpr),
-				    proplen);
-				prop[proplen] = '\0';
-			}
-		}
+	gpr = xcb_get_property_reply(conn, xcb_get_property(conn, 0, id,
+	    a_swm_ws, XCB_ATOM_STRING, 0, SWM_PROPLEN), NULL);
+	if (gpr && gpr->type == XCB_ATOM_STRING && gpr->format == 8) {
+		ws_idx = strtoint32(xcb_get_property_value(gpr), -1,
+		    workspace_limit - 1, &fail);
+		if (fail)
+			ws_idx = -2;
 	}
 	free(gpr);
 
-	if (prop) {
-		DNPRINTF(SWM_D_PROP, "_SWM_WS: %s\n", prop);
-		ws_idx = (int)strtonum(prop, -1, workspace_limit - 1, &errstr);
-		if (errstr) {
-			DNPRINTF(SWM_D_PROP, "win #%s: %s", errstr, prop);
-		}
-		free(prop);
-	}
-
+	DNPRINTF(SWM_D_PROP, "_SWM_WS: %d\n", ws_idx);
 	return (ws_idx);
 }
 
@@ -13781,14 +13769,12 @@ get_ws_id(struct ws_win *win)
 
 	gpr = xcb_get_property_reply(conn, xcb_get_property(conn, 0, win->id,
 	    ewmh[_NET_WM_DESKTOP].atom, XCB_ATOM_CARDINAL, 0, 1), NULL);
-	if (gpr) {
-		if (gpr->type == XCB_ATOM_CARDINAL && gpr->format == 32) {
-			val = *((uint32_t *)xcb_get_property_value(gpr));
-			DNPRINTF(SWM_D_PROP, "get _NET_WM_DESKTOP: %#x\n", val);
-			wsid = (val == EWMH_ALL_DESKTOPS ? -1 : (int)val);
-		}
-		free(gpr);
+	if (gpr && gpr->type == XCB_ATOM_CARDINAL && gpr->format == 32) {
+		val = *((uint32_t *)xcb_get_property_value(gpr));
+		DNPRINTF(SWM_D_PROP, "get _NET_WM_DESKTOP: %#x\n", val);
+		wsid = (val == EWMH_ALL_DESKTOPS ? -1 : (int)val);
 	}
+	free(gpr);
 
 	if (wsid == -2 && !(win->quirks & SWM_Q_IGNORESPAWNWS))
 		wsid = get_swm_ws(win->id);
@@ -13977,9 +13963,6 @@ manage_window(xcb_window_t id, int spawn
 
 	free(gr);
 
-	TAILQ_INSERT_TAIL(&s->managed, win, manage_entry);
-	s->managed_count++;
-
 	/* Select which X events to monitor and set border pixel color. */
 	wa[0] = XCB_EVENT_MASK_ENTER_WINDOW | XCB_EVENT_MASK_PROPERTY_CHANGE |
 	    XCB_EVENT_MASK_STRUCTURE_NOTIFY;
@@ -14081,6 +14064,10 @@ manage_window(xcb_window_t id, int spawn
 	if (win->ws == NULL)
 		win->ws = s->r->ws; /* Failsafe. */
 
+	/* WS must be valid before adding to managed list. */
+	TAILQ_INSERT_TAIL(&s->managed, win, manage_entry);
+	s->managed_count++;
+
 	/* Set the _NET_WM_DESKTOP atom. */
 	DNPRINTF(SWM_D_PROP, "set _NET_WM_DESKTOP: %d\n", win->ws->idx);
 	xcb_change_property(conn, XCB_PROP_MODE_REPLACE, win->id,
@@ -14155,6 +14142,9 @@ manage_window(xcb_window_t id, int spawn
 	if (win->quirks & SWM_Q_ANYWHERE)
 		new_flags |= SWM_F_MANUAL;
 
+	if (win->maxstackmax && ws_maxstack(win->ws))
+		new_flags |= EWMH_F_MAXIMIZED;
+
 	ewmh_apply_flags(win, new_flags);
 	ewmh_update_wm_state(win);
 
@@ -15226,7 +15216,6 @@ get_mapping_notify_label(uint8_t request
 
 	return (label);
 }
-#endif
 
 void
 mappingnotify(xcb_mapping_notify_event_t *e)
@@ -15474,7 +15463,7 @@ propertynotify(xcb_property_notify_event
 
 	if (e->atom == XCB_ATOM_WM_CLASS ||
 	    e->atom == XCB_ATOM_WM_NAME) {
-		if (win->ws && win->ws->r)
+		if (win->ws->r)
 			bar_draw(win->ws->r->bar);
 	} else if (e->atom == XCB_ATOM_WM_HINTS) {
 		get_wm_hints(win);
@@ -16636,7 +16625,7 @@ setup_extensions(void)
 			free(xiqvr);
 		}
 	}
-#endif
+#endif /* SWM_XCB_HAS_XINPUT */
 }
 
 void
