# $NetBSD: Makefile,v 1.8 2001/02/17 17:06:59 wiz Exp $

DISTNAME=		XBanner1.31
PKGNAME=		xbanner-1.31
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.digital.com/pub/linux/XBanner/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://chaos.fullerton.edu/XBanner/
COMMENT=		Make XDM login screen look pretty

USE_IMAKE=		YES
USE_XPM=		YES

NO_INSTALL_MANPAGES=	YES

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
