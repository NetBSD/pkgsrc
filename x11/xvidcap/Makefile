# $NetBSD: Makefile,v 1.22 2012/10/23 10:24:23 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		14
COMMENT=		Capture X display to individual frames or MPEG video

CONFIGURE_ARGS+=	--without-gtk2
LDFLAGS.DragonFly=	-lXt -lX11

.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
