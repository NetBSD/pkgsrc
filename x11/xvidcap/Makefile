# $NetBSD: Makefile,v 1.26 2014/08/11 23:09:46 wiz Exp $

.include "Makefile.common"

PKGREVISION=		17
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
