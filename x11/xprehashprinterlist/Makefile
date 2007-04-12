# $NetBSD: Makefile,v 1.1.1.1 2007/04/12 15:08:22 joerg Exp $
#

DISTNAME=		xprehashprinterlist-1.0.1
CATEGORIES=		x11 print
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Recompute Xprint server list

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
