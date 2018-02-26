# $NetBSD: Makefile,v 1.31 2018/02/26 08:19:32 adam Exp $

.include "Makefile.common"

PKGREVISION=		22
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
