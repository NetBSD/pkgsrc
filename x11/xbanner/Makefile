# $NetBSD: Makefile,v 1.10 2001/09/14 03:19:22 jlam Exp $

DISTNAME=		XBanner1.31
PKGNAME=		xbanner-1.31
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.digital.com/pub/linux/XBanner/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://chaos.fullerton.edu/XBanner/
COMMENT=		Make XDM login screen look pretty

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES
DOCDIR=			${PREFIX}/share/doc/xbanner

do-install:
	for f in freetemp random_effect xb_check xbanner; do		\
		${INSTALL_PROGRAM} ${WRKSRC}/$$f ${PREFIX}/bin;		\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xbanner
	for f in Changes.txt Credits.txt Resource_Reference.html	\
		XBanner_Users_Manual.html email.gif fonttips.html	\
		index.html red_line.gif rnd_doc.html stars.gif		\
		xb_check.html; do					\
		${INSTALL_DATA} ${WRKSRC}/docs/$$f ${DOCDIR};		\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/samples/XBanner.ad			\
		${PREFIX}/lib/X11/app-defaults/XBanner

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
