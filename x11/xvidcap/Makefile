# $NetBSD: Makefile,v 1.14 2009/08/26 20:24:12 sno Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		8
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
