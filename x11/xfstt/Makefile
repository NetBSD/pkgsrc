# $NetBSD: Makefile,v 1.3 2001/02/18 04:34:15 hubertf Exp $
#

DISTNAME=		xfstt-1.1
PKGNAME=		${DISTNAME}nb1
CATEGORIES=		x11 net
MASTER_SITES=		${MASTER_SITE_SUNSITE:=X11/fonts/}

MAINTAINER=		packages@netbsd.org
COMMENT=		TrueType font server for X11

USE_X11BASE=		YES

post-patch:
	@( \
	cd ${WRKSRC} ; \
	for i in INSTALL perftest.cpp xfstt.cpp ; \
	do \
	    ${MV} $$i $$i.bak ; \
	    ${SED} -e 's;@X11BASE@;${X11BASE};' < $$i.bak > $$i ; \
	done ; \
	)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xfstt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xfstt.1x ${PREFIX}/man/man1/xfstt.1
	${MKDIR} ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA} ${WRKSRC}/FAQ ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/xfstt
	${INSTALL_DATA} ${WRKSRC}/THANKS.txt ${PREFIX}/share/doc/xfstt
	${SED} -e "/%%PREFIX%%/s##${PREFIX}#g" ${FILESDIR}/xfstt.sh \
		> ${PREFIX}/etc/rc.d/xfstt
	${CHMOD} 755 ${PREFIX}/etc/rc.d/xfstt
	$(INSTALL_DATA_DIR) $(PREFIX)/lib/X11/fonts/TrueType
	${ECHO} belongs to xfstt pkg >$(PREFIX)/lib/X11/fonts/TrueType/.keepme

.include "../../mk/bsd.pkg.mk"
