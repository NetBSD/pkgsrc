# $NetBSD: Makefile,v 1.3 2007/01/14 10:30:56 joerg Exp $
#

DISTNAME=		xtrans-1.0.3
CATEGORIES=		x11 net
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Network API translation layer to insulate X

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xtrans.pc.in

.include "../../mk/bsd.pkg.mk"
