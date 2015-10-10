$NetBSD: patch-src_ws.c,v 1.1 2015/10/10 20:02:52 tnn Exp $

--- src/ws.c.orig	2015-08-29 08:48:29.000000000 +0000
+++ src/ws.c
@@ -550,9 +550,11 @@ wsReadHwState(InputInfoPtr pInfo, wsHwSt
 		case WSCONS_EVENT_MOUSE_ABSOLUTE_W:
 			/* ignore those */
 			continue;
+#ifdef WSCONS_EVENT_SYNC
 		case WSCONS_EVENT_SYNC:
 			DBG(4, ErrorF("Sync\n"));
 			return TRUE;
+#endif
 		default:
 			xf86IDrvMsg(pInfo, X_WARNING,
 			    "bad wsmouse event type=%d\n", event->type);
@@ -793,17 +795,23 @@ wsSetCalibProperty(DeviceIntPtr device, 
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
