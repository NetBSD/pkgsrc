$NetBSD: patch-clients_xmtg_ui.c,v 1.1 2013/02/26 10:18:42 joerg Exp $

--- clients/xmtg/ui.c.orig	2013-02-25 14:14:41.000000000 +0000
+++ clients/xmtg/ui.c
@@ -51,6 +51,12 @@ typedef long intptr_t; /* best guess... 
 #include "ui.h"
 #include "callbacks.h"
 
+void
+ui_create_drop_dialog(dialog_t *dp, Widget parent, char *prompt);
+
+void
+ui_create_add_dialog(dialog_t *dp, Widget parent, char *prompt, int floor, int seat, int view);
+
 dialog_t *open_d;
 dialog_t *save_d;
 dialog_t *add_d;
@@ -207,11 +213,7 @@ printf("BLORT!\n");
 }
 
 void
-ui_create_add_dialog(dp, parent, prompt, floor, seat, view)
-   dialog_t *dp;
-   Widget parent;
-   char *prompt;
-   int floor, seat, view;
+ui_create_add_dialog(dialog_t *dp, Widget parent, char *prompt, int floor, int seat, int view)
 {
    Widget w, input, radio;
    add_d_t *adp;
@@ -267,10 +269,7 @@ XtAddCallback(dp->enable, XtNcallback, b
 }
 
 void
-ui_create_drop_dialog(dp, parent, prompt)
-   dialog_t *dp;
-   Widget parent;
-   char *prompt;
+ui_create_drop_dialog(dialog_t *dp, Widget parent, char *prompt)
 {
    Widget w;
 
