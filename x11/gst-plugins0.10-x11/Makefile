# $NetBSD: Makefile,v 1.7 2011/05/18 09:49:03 drochner Exp $
#

GST_PLUGINS0.10_NAME=	x11
GST_PLUGINS0.10_DIRS=	sys/ximage sys/xvimage
GST_PLUGINS0.10_FLAGS=	x xshm xvideo

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
