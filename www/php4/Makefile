# $NetBSD: Makefile,v 1.7 2001/01/25 17:18:07 jlam Exp $

.include "../../www/php4/Makefile.common"

PKGNAME=		php-${PHP_VERS}
CATEGORIES+=		lang

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.php.net/

CONFLICTS+=		ap-php-4.0.3pl1

MESSAGE_FILE=		${WRKDIR}/.MESSAGE

pre-install:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/cgi-bin
	${LN} -sf ../../bin/php ${PREFIX}/libexec/cgi-bin/php
	${TOUCH} ${PREFIX}/${PHP_EXTENSION_DIR}/.directory
	${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/php.ini-optimized ${PREFIX}/etc
	${INSTALL_DATA_DIR} ${PREFIX}/share/php4
	${INSTALL_DATA} ${WRKSRC}/php4.gif ${PREFIX}/share/php4

.include "../../mk/bsd.pkg.mk"
