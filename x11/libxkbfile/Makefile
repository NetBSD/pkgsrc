# $NetBSD: Makefile,v 1.1.1.1 2006/11/07 17:18:15 joerg Exp $
#

DISTNAME=		libxkbfile-1.0.4
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		The xkbfile Library from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	xkbfile.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
