# $NetBSD: Makefile,v 1.38 2002/10/23 06:09:41 jlam Exp $

PKGNAME=		php-${BASE_VERS}
PKGREVISION?=		2
CATEGORIES+=		lang
COMMENT=		HTML-embedded programming language

.include "Makefile.common"

USE_PERL5=		build

CPPFLAGS+=		-DPHP_INTERNAL_FUNCS
FILES_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}

.if ${OPSYS} == Linux
LIBS+=	-lnsl
.endif

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php3
DATADIR=		${PREFIX}/share/php3

OWN_DIRS=		${PREFIX}/${PHP_EXTENSION_DIR}
CONF_FILES=		${EGDIR}/php3.ini.example ${PKG_SYSCONFDIR}/php3.ini

BUILD_DIRS=		${WRKSRC} ${WRKSRC}/convertor

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/php3.ini.example		\
		> ${WRKDIR}/php3.ini.example

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/php ${CGIDIR}/php
	${INSTALL_PROGRAM} ${WRKSRC}/convertor/convertor		\
		${PREFIX}/bin/php2convert
	${LN} -sf ${CGIDIR}/php ${PREFIX}/bin/php
	${INSTALL_DATA_DIR} ${DATADIR} ${EGDIR}
	cd ${WRKSRC}/extra/icons; ${INSTALL_DATA} * ${DATADIR}
	cd ${WRKSRC}/examples; ${INSTALL_DATA} README* *.php3 ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/php3.ini.example ${EGDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
