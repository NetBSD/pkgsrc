# $NetBSD: Makefile,v 1.10 2025/02/08 04:07:18 taca Exp $
#

PWVER=		15.1.0
PKGREVISION=	1
DISTNAME=	piwigo-${PWVER}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	-http://piwigo.org/download/dlcounter.php?code=${PWVER}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://piwigo.org/
COMMENT=	Piwigo is photo gallery software for the web
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=${PHP_BASE_VERS}:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=${PHP_BASE_VERS}:../../databases/php-mysqli

WRKSRC=		${WRKDIR}/piwigo
USE_LANGUAGES=	# none

NO_BUILD=	yes
USE_TOOLS+=	pax

PW_DIR=		share/piwigo
INSTALLATION_DIRS=	${PW_DIR} ${PW_DIR}/upload

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		PW_DIR=${PW_DIR}

post-extract:
	cd ${WRKSRC} && ${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

do-install:
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${PW_DIR}

	touch ${DESTDIR}${PREFIX}/${PW_DIR}/upload/.empty

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
