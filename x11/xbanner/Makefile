# $NetBSD: Makefile,v 1.2 1998/08/18 22:29:22 tron Exp $

DISTNAME=		XBanner1.31
PKGNAME=		xbanner-1.31
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.digital.com/pub/linux/XBanner/

MAINTAINER=		root@garbled.net

DEPENDS+=		xpm-3.4k:../../graphics/xpm

NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

post-install:
	@${MKDIR} ${X11BASE}/share/doc/xbanner
.for FILE in Changes.txt Credits.txt Resource_Reference.html \
             XBanner_Users_Manual.html email.gif fonttips.html index.html \
             red_line.gif rnd_doc.html stars.gif xb_check.html
	${INSTALL_DATA} ${WRKSRC}/docs/${FILE} ${X11BASE}/share/doc/xbanner
.endfor
	${INSTALL_DATA} ${WRKSRC}/samples/XBanner.ad \
	  ${X11BASE}/lib/X11/app-defaults/XBanner

.include "../../mk/bsd.pkg.mk"
