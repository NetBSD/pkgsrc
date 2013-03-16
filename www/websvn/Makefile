# $NetBSD: Makefile,v 1.23 2013/03/16 07:21:26 obache Exp $
#

DISTNAME=	websvn-2.2.1
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/45918/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.websvn.info/
COMMENT=	Subversion repository web frontend

DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib

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
SUBST_SED.conf=		-e "s|@EGDIR@|${EGDIR}|g"
SUBST_SED.conf+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"

INSTALLATION_DIRS=	${HTTPD_ROOT}/websvn share/examples/websvn

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/distconfig.php ${DESTDIR}${EGDIR}
	cd ${WRKSRC} && rm -f *.orig */*.orig
	cd ${WRKSRC} && pax -rwppm . ${DESTDIR}${PREFIX}/${HTTPD_ROOT}/websvn
	${RM} ${DESTDIR}${PREFIX}/${HTTPD_ROOT}/websvn/include/distconfig.php

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
