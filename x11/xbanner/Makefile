# $NetBSD: Makefile,v 1.17 2008/01/19 09:16:26 wiz Exp $

DISTNAME=		XBanner1.31
PKGNAME=		xbanner-1.31
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hijinks.com/~spade/linux/XBanner/
COMMENT=		Make XDM login screen look pretty

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES
DOCDIR=			${PREFIX}/share/doc/xbanner

INSTALLATION_DIRS=	bin

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

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
