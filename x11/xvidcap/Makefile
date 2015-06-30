# $NetBSD: Makefile,v 1.27 2015/06/30 09:57:43 ryoon Exp $

.include "Makefile.common"

PKGREVISION=		18
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
