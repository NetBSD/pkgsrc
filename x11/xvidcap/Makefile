# $NetBSD: Makefile,v 1.28 2015/11/18 14:19:55 ryoon Exp $

.include "Makefile.common"

PKGREVISION=		19
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
