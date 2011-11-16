# $NetBSD: Makefile,v 1.19 2011/11/16 01:33:15 sbd Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		13
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
