# $NetBSD: Makefile,v 1.10 2013/07/12 10:45:04 jperkin Exp $
#

DISTNAME=	concrete5.6.1.2
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/concrete5/concrete5-5/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.concrete5.org/download_file/-/view/51635/8497/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.concrete5.org/
COMMENT=	Open sourece Content Management System
LICENSE=	mit

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.2.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.2.0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql

USE_LANGUAGES=	# none
NO_BUILD=	yes

USE_TOOLS+=	pax

BUILD_DEFS+=	APACHE_GROUP APACHE_USER

C5DIR=			share/concrete5
INSTALLATION_DIRS=	${C5DIR}

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		C5DIR=${C5DIR}

REPLACE_PYTHON+=	concrete/libraries/3rdparty/htmldiff.py

do-install:
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${C5DIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${C5DIR}/packages
	${TOUCH} ${DESTDIR}${PREFIX}/${C5DIR}/packages/.keep
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${C5DIR}/files
	${TOUCH} ${DESTDIR}${PREFIX}/${C5DIR}/files/.keep

.include "../../lang/php/phpversion.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
