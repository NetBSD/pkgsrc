# $NetBSD: Makefile,v 1.6 2000/07/11 10:55:32 agc Exp $

DISTNAME=		XBanner1.31
PKGNAME=		xbanner-1.31
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.digital.com/pub/linux/XBanner/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://chaos.fullerton.edu/XBanner/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

post-install:
	@${MKDIR} ${X11PREFIX}/share/doc/xbanner
	for f in Changes.txt Credits.txt Resource_Reference.html	\
		XBanner_Users_Manual.html email.gif fonttips.html	\
		index.html red_line.gif rnd_doc.html stars.gif		\
		xb_check.html; do					\
		${INSTALL_DATA} ${WRKSRC}/docs/$$f ${X11PREFIX}/share/doc/xbanner; \
	done
	${INSTALL_DATA} ${WRKSRC}/samples/XBanner.ad \
		${X11PREFIX}/lib/X11/app-defaults/XBanner

.include "../../mk/bsd.pkg.mk"
