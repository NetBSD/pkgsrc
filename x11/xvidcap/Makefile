# $NetBSD: Makefile,v 1.23 2012/10/29 05:07:23 asau Exp $
#

.include "Makefile.common"

PKGREVISION=		14
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
