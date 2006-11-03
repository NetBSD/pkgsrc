# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 21:40:59 joerg Exp $
#

DISTNAME=		libXv-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xv Extension library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xv.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
