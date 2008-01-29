# $NetBSD: Makefile,v 1.4 2008/01/29 03:50:25 bjs Exp $
#

DISTNAME=		libXdamage-1.1.1
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xdamage extension (Library)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xdamage.pc.in

.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
