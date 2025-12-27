$NetBSD: patch-src_ipc.c,v 1.1 2025/12/27 15:37:50 wiz Exp $

Check for uselocale() before using it.
https://github.com/i3/i3/issues/6566

--- src/ipc.c.orig	2025-12-19 07:19:53.000000000 +0000
+++ src/ipc.c
@@ -909,11 +909,18 @@ static void dump_bar_config(yajl_gen gen
 }
 
 IPC_HANDLER(tree) {
+#if HAVE_USELOCALE
     locale_t prev_locale = uselocale(numericC);
+#else
+    setlocale(LC_NUMERIC, "C");
+#endif
     yajl_gen gen = ygenalloc();
     dump_node(gen, croot, false);
+#if HAVE_USELOCALE
     uselocale(prev_locale);
-
+#else
+    setlocale(LC_NUMERIC, "");
+#endif
     const unsigned char *payload;
     ylength length;
     y(get_buf, &payload, &length);
@@ -1585,7 +1592,11 @@ ipc_client *ipc_new_client_on_fd(EV_P_ i
  * generator. Free with yajl_gen_free().
  */
 yajl_gen ipc_marshal_workspace_event(const char *change, Con *current, Con *old) {
+#if HAVE_USELOCALE
     locale_t prev_locale = uselocale(numericC);
+#else
+    setlocale(LC_NUMERIC, "C");
+#endif
     yajl_gen gen = ygenalloc();
 
     y(map_open);
@@ -1609,7 +1620,11 @@ yajl_gen ipc_marshal_workspace_event(con
 
     y(map_close);
 
+#if HAVE_USELOCALE
     uselocale(prev_locale);
+#else
+    setlocale(LC_NUMERIC, "");
+#endif
 
     return gen;
 }
@@ -1639,7 +1654,11 @@ void ipc_send_window_event(const char *p
     DLOG("Issue IPC window %s event (con = %p, window = 0x%08x)\n",
          property, con, (con->window ? con->window->id : XCB_WINDOW_NONE));
 
+#if HAVE_USELOCALE
     locale_t prev_locale = uselocale(numericC);
+#else
+    setlocale(LC_NUMERIC, "C");
+#endif
     yajl_gen gen = ygenalloc();
 
     y(map_open);
@@ -1658,7 +1677,11 @@ void ipc_send_window_event(const char *p
 
     ipc_send_event("window", I3_IPC_EVENT_WINDOW, (const char *)payload);
     y(free);
+#if HAVE_USELOCALE
     uselocale(prev_locale);
+#else
+    setlocale(LC_NUMERIC, "");
+#endif
 }
 
 /*
@@ -1666,7 +1689,11 @@ void ipc_send_window_event(const char *p
  */
 void ipc_send_barconfig_update_event(Barconfig *barconfig) {
     DLOG("Issue barconfig_update event for id = %s\n", barconfig->id);
+#if HAVE_USELOCALE
     locale_t prev_locale = uselocale(numericC);
+#else
+    setlocale(LC_NUMERIC, "C");
+#endif
     yajl_gen gen = ygenalloc();
 
     dump_bar_config(gen, barconfig);
@@ -1677,7 +1704,11 @@ void ipc_send_barconfig_update_event(Bar
 
     ipc_send_event("barconfig_update", I3_IPC_EVENT_BARCONFIG_UPDATE, (const char *)payload);
     y(free);
+#if HAVE_USELOCALE
     uselocale(prev_locale);
+#else
+    setlocale(LC_NUMERIC, "");
+#endif
 }
 
 /*
@@ -1686,7 +1717,11 @@ void ipc_send_barconfig_update_event(Bar
 void ipc_send_binding_event(const char *event_type, Binding *bind, const char *modename) {
     DLOG("Issue IPC binding %s event (sym = %s, code = %d)\n", event_type, bind->symbol, bind->keycode);
 
+#if HAVE_USELOCALE
     locale_t prev_locale = uselocale(numericC);
+#else
+    setlocale(LC_NUMERIC, "C");
+#endif
 
     yajl_gen gen = ygenalloc();
 
@@ -1714,7 +1749,11 @@ void ipc_send_binding_event(const char *
     ipc_send_event("binding", I3_IPC_EVENT_BINDING, (const char *)payload);
 
     y(free);
+#if HAVE_USELOCALE
     uselocale(prev_locale);
+#else
+    setlocale(LC_NUMERIC, "");
+#endif
 }
 
 /*
