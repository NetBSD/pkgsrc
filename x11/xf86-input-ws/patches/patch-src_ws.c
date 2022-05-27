$NetBSD: patch-src_ws.c,v 1.2 2022/05/27 02:35:43 tnn Exp $

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
 
@@ -611,9 +610,11 @@ wsReadHwState(InputInfoPtr pInfo, wsHwSt
 		case WSCONS_EVENT_MOUSE_ABSOLUTE_W:
 			/* ignore those */
 			continue;
+#ifdef WSCONS_EVENT_SYNC
 		case WSCONS_EVENT_SYNC:
 			DBG(4, ErrorF("Sync\n"));
 			return TRUE;
+#endif
 		case WSCONS_EVENT_HSCROLL:
 			hw->hscroll = event->value;
 			DBG(4, ErrorF("Horiz. Scrolling %d\n", event->value));
@@ -876,17 +877,23 @@ wsSetCalibProperty(DeviceIntPtr device, 
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
