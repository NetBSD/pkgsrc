# $NetBSD: Makefile,v 1.1 1998/08/18 21:54:39 tron Exp $

DISTNAME=		XBanner1.31
PKGNAME=		xbanner-1.31
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.digital.com/pub/linux/XBanner/

MAINTAINER=		root@garbled.net

DEPENDS+=		xpm-3.4k:../../graphics/xpm

NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

post-install:
	@${MKDIR} ${X11BASE}/share/examples/xbanner
	@${MKDIR} ${X11BASE}/share/doc/xbanner
	${CP} -R ${WRKSRC}/docs/* ${X11BASE}/share/doc/xbanner
	${CP} -R ${WRKSRC}/samples/* ${X11BASE}/share/examples/xbanner

.include "../../mk/bsd.pkg.mk"
