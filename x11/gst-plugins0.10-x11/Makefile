# $NetBSD: Makefile,v 1.5 2008/06/20 01:09:44 joerg Exp $
#

GST_PLUGINS0.10_NAME=	x11
GST_PLUGINS0.10_DIRS=	sys/ximage sys/xvimage
GST_PLUGINS0.10_FLAGS=	x xshm xvideo

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
