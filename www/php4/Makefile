# $NetBSD: Makefile,v 1.9 2001/02/17 17:22:31 wiz Exp $

.include "../../www/php4/Makefile.common"

PKGNAME=		php-${PHP_VERS}
CATEGORIES+=		lang

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.php.net/
COMMENT=		PHP4: Hypertext Preprocessor

CONFLICTS+=		ap-php-4.0.3pl1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/cgi-bin
	${LN} -sf ../../bin/php ${PREFIX}/libexec/cgi-bin/php
	${TOUCH} ${PREFIX}/${PHP_EXTENSION_DIR}/.directory
	${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/php.ini-optimized ${PREFIX}/etc
	${INSTALL_DATA_DIR} ${PREFIX}/share/php4
	${INSTALL_DATA} ${WRKSRC}/php4.gif ${PREFIX}/share/php4

.include "../../mk/bsd.pkg.mk"
