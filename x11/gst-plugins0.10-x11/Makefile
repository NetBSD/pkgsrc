# $NetBSD: Makefile,v 1.6 2011/04/24 15:31:09 obache Exp $
#

GST_PLUGINS0.10_NAME=	x11
GST_PLUGINS0.10_DIRS=	sys/ximage sys/xvimage
GST_PLUGINS0.10_FLAGS=	x xshm xvideo

PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../multimedia/gst-plugins0.10-base/Makefile.common"

.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
