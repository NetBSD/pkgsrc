# $NetBSD: Makefile,v 1.1.1.1 2006/11/14 14:58:54 joerg Exp $
#

DISTNAME=		libXxf86misc-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/lib/
COMMENT=		Library for the XFree86-Misc X extension

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xxf86misc.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
