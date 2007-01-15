# $NetBSD: Makefile,v 1.4 2007/01/15 16:23:33 joerg Exp $
#

GST_PLUGINS0.10_NAME=	x11
GST_PLUGINS0.10_DIRS=	sys/ximage sys/xvimage
GST_PLUGINS0.10_FLAGS=	x xshm xvideo

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
