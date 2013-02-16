# $NetBSD: Makefile,v 1.24 2013/02/16 11:25:33 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=		15
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
