# $NetBSD: Makefile,v 1.13 2001/07/13 07:09:26 jlam Exp $

.include "../../www/php4/Makefile.common"

PKGNAME=		php-${PHP_VERS}
CATEGORIES+=		lang

COMMENT=		PHP4: Hypertext Preprocessor

CONFLICTS+=		ap-php-4.0.3pl1

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		PHP_CONFDIR=${PHP_CONFDIR}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA_DIR} ${CGIDIR}
	${LN} -sf ../../bin/php ${CGIDIR}/php
	${TOUCH} ${PREFIX}/${PHP_EXTENSION_DIR}/.directory
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-optimized ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/php
	${INSTALL_DATA} ${WRKSRC}/php4.gif ${PREFIX}/share/php
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
