# $NetBSD: Makefile,v 1.32 2002/01/10 13:17:11 jlam Exp $

PKGNAME=		php-${BASE_VERS}
PKGREVISION?=		# empty
CATEGORIES+=		lang
COMMENT=		HTML-embedded programming language

USE_BUILDLINK_ONLY=	yes

.include "Makefile.common"

BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

CPPFLAGS+=		-DPHP_INTERNAL_FUNCS
FILES_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php3
DATADIR=		${PREFIX}/share/php3

OWN_DIRS=		${PREFIX}/${PHP_EXTENSION_DIR}
CONF_FILES=		${EGDIR}/php3.ini.example ${PKG_SYSCONFDIR}/php3.ini

post-build:
	cd ${WRKSRC}/convertor; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/php3.ini.example		\
		> ${WRKDIR}/php3.ini.example

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/php ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/convertor/convertor		\
		${PREFIX}/bin/php2convert
	${LN} -sf ../../bin/php ${CGIDIR}/php
	${INSTALL_DATA_DIR} ${DATADIR} ${EGDIR}
	cd ${WRKSRC}/extra/icons; ${INSTALL_DATA} * ${DATADIR}
	cd ${WRKSRC}/examples; ${INSTALL_DATA} README* *.php3 ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/php3.ini.example ${EGDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
