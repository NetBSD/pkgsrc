# $NetBSD: Makefile,v 1.30 2017/01/16 23:45:17 wiz Exp $

.include "Makefile.common"

PKGREVISION=		21
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
