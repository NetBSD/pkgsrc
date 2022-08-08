$NetBSD: patch-src_ws.c,v 1.3 2022/08/08 13:53:57 nia Exp $

ws.c:407:3: warning: attempt to free a non-heap object
Reported to upstream maintainers.

--- src/ws.c.orig	2022-05-27 02:04:14.000000000 +0000
+++ src/ws.c
@@ -404,7 +404,6 @@ wsDeviceInit(DeviceIntPtr pWS)
 	    axes_labels[VSCROLL_AXIS], 0, -1, 0, 0, 0, Relative);
 	priv->scroll_mask = valuator_mask_new(MAX_VALUATORS);
 	if (!priv->scroll_mask) {
-		free(axes_labels);
 		return !Success;
 	}
 
@@ -611,17 +610,23 @@ wsReadHwState(InputInfoPtr pInfo, wsHwSt
 		case WSCONS_EVENT_MOUSE_ABSOLUTE_W:
 			/* ignore those */
 			continue;
+#ifdef WSCONS_EVENT_SYNC
 		case WSCONS_EVENT_SYNC:
 			DBG(4, ErrorF("Sync\n"));
 			return TRUE;
+#endif
+#ifdef WSCONS_EVENT_HSCROLL
 		case WSCONS_EVENT_HSCROLL:
 			hw->hscroll = event->value;
 			DBG(4, ErrorF("Horiz. Scrolling %d\n", event->value));
 			return TRUE;
+#endif
+#ifdef WSCONS_EVENT_VSCROLL
 		case WSCONS_EVENT_VSCROLL:
 			hw->vscroll = event->value;
 			DBG(4, ErrorF("Vert. Scrolling %d\n", event->value));
 			return TRUE;
+#endif
 		default:
 			xf86IDrvMsg(pInfo, X_WARNING,
 			    "bad wsmouse event type=%d\n", event->type);
@@ -876,17 +881,23 @@ wsSetCalibProperty(DeviceIntPtr device, 
 		priv->coords.maxx = priv->max_x;
 		priv->coords.miny = priv->min_y;
 		priv->coords.maxy = priv->max_y;
+#ifdef __OpenBSD__
 		priv->coords.swapxy = priv->swap_axes;
+#endif
 
 		/* Update the kernel calibration table */
 		coords.minx = priv->min_x;
 		coords.maxx = priv->max_x;
 		coords.miny = priv->min_y;
 		coords.maxy = priv->max_y;
+#ifdef __OpenBSD__
 		coords.swapxy = priv->swap_axes;
+#endif
 		coords.samplelen = priv->raw;
+#ifdef __OpenBSD__
 		coords.resx = priv->coords.resx;
 		coords.resy = priv->coords.resy;
+#endif
 		if (ioctl(pInfo->fd, WSMOUSEIO_SCALIBCOORDS, &coords) != 0) {
 			xf86IDrvMsg(pInfo, X_ERROR, "SCALIBCOORDS failed %s\n",
 			    strerror(errno));
