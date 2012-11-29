# $NetBSD: Makefile,v 1.1 2012/11/29 08:38:20 ryoon Exp $
#

GST_PLUGINS1_NAME=	x11
GST_PLUGINS1_DIRS=	sys/ximage sys/xvimage
GST_PLUGINS1_FLAGS=	x xshm xvideo

.include "../../multimedia/gst-plugins1-base/Makefile.common"

.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
