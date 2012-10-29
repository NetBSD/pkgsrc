# $NetBSD: Makefile,v 1.5 2012/10/29 05:06:08 asau Exp $
#

DISTNAME=		bigreqsproto-1.1.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		BigReqs extension headers from modular Xorg X11

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/bigreqsproto.pc.in
USE_LANGUAGES=		c

.include "../../mk/bsd.pkg.mk"
