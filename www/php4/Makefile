# $NetBSD: Makefile,v 1.3 2000/12/17 21:33:55 jlam Exp $

.include "../../www/php4/Makefile.common"

CATEGORIES+=		lang

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.php.net/

CONFLICTS+=		ap-php-4.0.3pl1

MESSAGE_FILE=		${WRKDIR}/.MESSAGE

BINDIR=			${PREFIX}/bin
CGIDIR=			${PREFIX}/libexec/cgi-bin
LIBDIR=			${PREFIX}/lib

pre-install:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

do-install:
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/php ${BINDIR}
	${INSTALL_DATA_DIR} ${CGIDIR}
	${RM} -f ${CGIDIR}/php
	${LN} -sf ../../bin/php ${CGIDIR}/php
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libphp4.la ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/php.ini-optimized ${PREFIX}/etc
	${INSTALL_DATA_DIR} ${PREFIX}/share/php4
	${INSTALL_DATA} ${WRKSRC}/php4.gif ${PREFIX}/share/php4

.include "../../mk/bsd.pkg.mk"
