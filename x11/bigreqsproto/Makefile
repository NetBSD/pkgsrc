# $NetBSD: Makefile,v 1.4 2012/06/03 18:36:16 wiz Exp $
#

DISTNAME=		bigreqsproto-1.1.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		BigReqs extension headers from modular Xorg X11

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/bigreqsproto.pc.in
USE_LANGUAGES=		c

.include "../../mk/bsd.pkg.mk"
