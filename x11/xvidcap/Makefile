# $NetBSD: Makefile,v 1.25 2014/04/10 05:39:17 obache Exp $
#

.include "Makefile.common"

PKGREVISION=		16
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
