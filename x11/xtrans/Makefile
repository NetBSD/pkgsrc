# $NetBSD: Makefile,v 1.9 2008/05/09 22:53:21 dsainty Exp $
#

DISTNAME=		xtrans-1.2
PKGREVISION=		1
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
