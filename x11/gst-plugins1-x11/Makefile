# $NetBSD: Makefile,v 1.3 2020/03/08 16:51:42 wiz Exp $

GST_PLUGINS1_NAME=	x11
GST_PLUGINS1_DIRS=	sys/ximage sys/xvimage
GST_PLUGINS1_FLAGS=	x xshm xvideo

PKGREVISION= 1
.include "../../multimedia/gst-plugins1-base/Makefile.common"

.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
