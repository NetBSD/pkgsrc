# $NetBSD: Makefile,v 1.11 2001/04/30 03:25:15 jlam Exp $

.include "../../www/php4/Makefile.common"

PKGNAME=		php-${PHP_VERS}
CATEGORIES+=		lang

COMMENT=		PHP4: Hypertext Preprocessor

CONFLICTS+=		ap-php-4.0.3pl1

EGDIR=			${PREFIX}/share/examples/php

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/cgi-bin
	${LN} -sf ../../bin/php ${PREFIX}/libexec/cgi-bin/php
	${TOUCH} ${PREFIX}/${PHP_EXTENSION_DIR}/.directory
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-optimized ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/php
	${INSTALL_DATA} ${WRKSRC}/php4.gif ${PREFIX}/share/php

.include "../../mk/bsd.pkg.mk"
