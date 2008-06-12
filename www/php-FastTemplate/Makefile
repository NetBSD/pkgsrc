# $NetBSD: Makefile,v 1.12 2008/06/12 02:14:56 joerg Exp $

DISTNAME=	FastTemplate-1_1_0
PKGNAME=	${PHP_PKG_PREFIX}-FastTemplate-1.1.0
CATEGORIES=	www php4
MASTER_SITES=	http://www.thewebmasters.net/php/

PATCHFILES=	php4.diff
PATCH_SITES=	http://www.thewebmasters.net/php/FastTemplate/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.thewebmasters.net/php/FastTemplate.phtml
COMMENT=	PHP extension for managing templates and variable interpolation

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-FastTemplate-[0-9]*

PHP_VERSIONS_ACCEPTED=	4

WRKSRC=		${WRKDIR}/FastTemplate
DIST_SUBDIR=	${PKGBASE}

NO_BUILD=	YES

PHP_LIB_SUBDIR=	lib/php
PHP_LIB_DIR=	${PREFIX}/${PHP_LIB_SUBDIR}
DOCDIR=		${PREFIX}/share/doc/html/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

PLIST_SUBST+=	PHP_LIB_SUBDIR=${PHP_LIB_SUBDIR:Q}
PLIST_SUBST+=	PKGBASE=${PKGBASE:Q}

INSTALLATION_DIRS=	${PHP_LIB_DIR} ${DOCDIR} ${EGDIR}/templates

do-install:
	${INSTALL_DATA} ${WRKSRC}/class.FastTemplate.php3 ${DESTDIR}${PHP_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FastTemplate.html ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}; for file in *.phtml; do				\
		dest=${DESTDIR}${EGDIR}/`${BASENAME} $${file} .phtml`.php; \
		${INSTALL_DATA} $${file} $${dest};			\
	done
	${INSTALL_DATA} ${WRKSRC}/templates/*.tpl ${DESTDIR}${EGDIR}/templates

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
