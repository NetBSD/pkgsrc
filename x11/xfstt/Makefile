# $NetBSD: Makefile,v 1.10 2002/09/27 17:03:21 grant Exp $
#

DISTNAME=		xfstt_1.3
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		x11 net
PKGREVISION=		1
MASTER_SITES=		http://download.berlios.de/xfstt/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://developer.berlios.de/projects/xfstt
COMMENT=		TrueType font server for X11

CXXFLAGS+=		-fomit-frame-pointer -ffast-math
MAKE_ENV+=		CXXFLAGS="${CXXFLAGS}"

USE_X11BASE=		YES
USE_GMAKE=		YES
WRKSRC=			${WRKDIR}/${PKGNAME}

RCD_SCRIPTS=		xfstt

post-patch:
	@( \
	cd ${WRKSRC} ; \
	for i in INSTALL perftest.cpp xfstt.cpp xfstt.1x; \
	do \
	    ${MV} $$i $$i.bak ; \
	    ${SED} -e 's;@PREFIX@;${PREFIX};' < $$i.bak > $$i ; \
	done ; \
	)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xfstt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xfstt.1x ${PREFIX}/man/man1/xfstt.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA} ${WRKSRC}/THANKS ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/TrueType
	${ECHO} belongs to xfstt pkg >${PREFIX}/lib/X11/fonts/TrueType/.keepme

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
