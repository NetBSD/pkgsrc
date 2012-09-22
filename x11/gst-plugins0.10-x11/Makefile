# $NetBSD: Makefile,v 1.9 2012/09/22 12:36:45 obache Exp $
#

GST_PLUGINS0.10_NAME=	x11
GST_PLUGINS0.10_DIRS=	sys/ximage sys/xvimage
GST_PLUGINS0.10_FLAGS=	x xshm xvideo
PKGREVISION=		2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
