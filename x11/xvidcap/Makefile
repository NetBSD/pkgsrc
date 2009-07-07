# $NetBSD: Makefile,v 1.13 2009/07/07 17:38:09 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		7
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
