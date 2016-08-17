# $NetBSD: Makefile,v 1.29 2016/08/17 00:06:47 ryoon Exp $

.include "Makefile.common"

PKGREVISION=		20
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
