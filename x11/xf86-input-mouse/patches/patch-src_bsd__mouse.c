$NetBSD: patch-src_bsd__mouse.c,v 1.2 2013/08/19 09:19:27 wiz Exp $

Add MSE_MISC on NetBSD as well, so mouse is found correctly.
Add absolute positioning support.

--- src/bsd_mouse.c.orig	2012-10-08 01:40:07.000000000 +0000
+++ src/bsd_mouse.c
@@ -97,9 +97,7 @@ static const char *mouseDevs[] = {
 static int
 SupportedInterfaces(void)
 {
-#if defined(__NetBSD__)
-    return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO;
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__NetBSD__)
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_AUTO | MSE_MISC;
 #else
     return MSE_SERIAL | MSE_BUS | MSE_PS2 | MSE_XPS2 | MSE_AUTO | MSE_MISC;
@@ -409,7 +407,7 @@ wsconsReadInput(InputInfoPtr pInfo)
     n /= sizeof(struct wscons_event);
     while( n-- ) {
         int buttons = pMse->lastButtons;
-        int dx = 0, dy = 0, dz = 0, dw = 0;
+        int dx = 0, dy = 0, dz = 0, dw = 0, x, y;
         switch (event->type) {
         case WSCONS_EVENT_MOUSE_UP:
 #define BUTBIT (1 << (event->value <= 2 ? 2 - event->value : event->value))
@@ -434,6 +432,30 @@ wsconsReadInput(InputInfoPtr pInfo)
             dw = event->value;
             break;
 #endif
+	case WSCONS_EVENT_MOUSE_ABSOLUTE_X:
+	    miPointerGetPosition (pInfo->dev, &x, &y);
+	    x = event->value;
+	    miPointerSetPosition (pInfo->dev, Absolute, (double *)&x, (double *)&y);
+	    xf86PostMotionEvent(pInfo->dev, TRUE, 0, 2, x, y);
+	    ++event;
+	    continue;
+	case WSCONS_EVENT_MOUSE_ABSOLUTE_Y:
+	    miPointerGetPosition (pInfo->dev, &x, &y);
+	    y = event->value;
+	    miPointerSetPosition (pInfo->dev, Absolute, (double *)&x, (double *)&y);
+	    xf86PostMotionEvent(pInfo->dev, TRUE, 0, 2, x, y);
+	    ++event;
+	    continue;
+#ifdef WSCONS_EVENT_MOUSE_ABSOLUTE_Z
+	case WSCONS_EVENT_MOUSE_ABSOLUTE_Z:
+	    ++event;
+	    continue;
+#endif
+#ifdef WSCONS_EVENT_MOUSE_ABSOLUTE_W
+	case WSCONS_EVENT_MOUSE_ABSOLUTE_W:
+	    ++event;
+	    continue;
+#endif
         default:
             LogMessageVerbSigSafe(X_WARNING, -1,
                                   "%s: bad wsmouse event type=%d\n", pInfo->name,
