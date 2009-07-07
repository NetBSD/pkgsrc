# $NetBSD: Makefile,v 1.18 2009/07/07 18:00:16 joerg Exp $

DISTNAME=		XBanner1.31
PKGNAME=		xbanner-1.31
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hijinks.com/~spade/linux/XBanner/
COMMENT=		Make XDM login screen look pretty

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES
DOCDIR=			${PREFIX}/share/doc/xbanner

INSTALLATION_DIRS=	bin lib/X11/app-defaults ${DOCDIR}

do-install:
	for f in freetemp random_effect xb_check xbanner; do		\
		${INSTALL_PROGRAM} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/bin;		\
	done
	for f in Changes.txt Credits.txt Resource_Reference.html	\
		XBanner_Users_Manual.html email.gif fonttips.html	\
		index.html red_line.gif rnd_doc.html stars.gif		\
		xb_check.html; do					\
		${INSTALL_DATA} ${WRKSRC}/docs/$$f ${DESTDIR}${DOCDIR};		\
	done
	${INSTALL_DATA} ${WRKSRC}/samples/XBanner.ad			\
		${DESTDIR}${PREFIX}/lib/X11/app-defaults/XBanner

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
