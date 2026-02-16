# $NetBSD: Makefile,v 1.29 2026/02/16 08:27:59 wiz Exp $

DISTNAME=	websvn-2.2.1
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.websvn.info/
COMMENT=	Subversion repository web frontend

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=${PHP_BASE_VERS}:../../archivers/php-zlib

NO_BUILD=	yes
USE_TOOLS+=	pax

MESSAGE_SUBST+=	PKGBASE=${PKGBASE}
MESSAGE_SUBST+=	HTTPD_ROOT=${HTTPD_ROOT}
PLIST_SUBST+=	HTTPD_ROOT=${HTTPD_ROOT:Q}

HTTPD_ROOT?=	share/httpd/htdocs

BUILD_DEFS+=	HTTPD_ROOT

EGDIR=		${PREFIX}/share/examples/websvn
CONF_FILES=	${EGDIR}/distconfig.php ${PKG_SYSCONFDIR}/websvn.conf

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	do-configure
SUBST_MESSAGE.conf=	Fixing paths to configuration files.
SUBST_FILES.conf=	include/setup.php
SUBST_VARS.conf=	EGDIR
SUBST_VARS.conf+=	PKG_SYSCONFDIR

INSTALLATION_DIRS=	${HTTPD_ROOT}/websvn share/examples/websvn

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/distconfig.php ${DESTDIR}${EGDIR}
	cd ${WRKSRC} && rm -f *.orig */*.orig
	cd ${WRKSRC} && pax -rwppm . ${DESTDIR}${PREFIX}/${HTTPD_ROOT}/websvn
	${RM} ${DESTDIR}${PREFIX}/${HTTPD_ROOT}/websvn/include/distconfig.php

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
