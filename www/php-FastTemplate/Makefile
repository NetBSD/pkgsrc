# $NetBSD: Makefile,v 1.6 2005/06/23 15:38:40 wiz Exp $

DISTNAME=	FastTemplate-1_1_0
PKGNAME=	php-FastTemplate-1.1.0
CATEGORIES=	www php4
MASTER_SITES=	http://www.thewebmasters.net/php/

PATCHFILES=	php4.diff
PATCH_SITES=	http://www.thewebmasters.net/php/FastTemplate/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.thewebmasters.net/php/FastTemplate.phtml
COMMENT=	PHP extension for managing templates and variable interpolation

DEPENDS+=	php>=3.0.18:../../www/php4

WRKSRC=		${WRKDIR}/FastTemplate
DIST_SUBDIR=	${PKGBASE}

NO_BUILD=	YES

PHP_LIB_SUBDIR=	lib/php
PHP_LIB_DIR=	${PREFIX}/${PHP_LIB_SUBDIR}
DOCDIR=		${PREFIX}/share/doc/html/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

PLIST_SUBST+=	PHP_LIB_SUBDIR=${PHP_LIB_SUBDIR}
PLIST_SUBST+=	PKGBASE=${PKGBASE}

do-install:
	${INSTALL_DATA_DIR} ${PHP_LIB_DIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/templates
	${INSTALL_DATA} ${WRKSRC}/class.FastTemplate.php3 ${PHP_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FastTemplate.html ${DOCDIR}
	cd ${WRKSRC}; for file in *.phtml; do				\
		dest=${EGDIR}/`${BASENAME} $${file} .phtml`.php;	\
		${INSTALL_DATA} $${file} $${dest};			\
	done
	${INSTALL_DATA} ${WRKSRC}/templates/*.tpl ${EGDIR}/templates

.include "../../mk/bsd.pkg.mk"
