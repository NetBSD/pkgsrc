# $NetBSD: Makefile,v 1.7 2025/02/08 04:07:18 taca Exp $

DISTNAME=	soycms_1.4.0c_mysql
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/_/-/:S/_mysql//}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
# https://www.soycms.net/download
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.soycms.net/
COMMENT=	Flexible and pluggable CMS
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=${PHP_BASE_VERS}:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=${PHP_BASE_VERS}:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

USE_TOOLS+=	pax

SOYDIR=		share/soycms
INSTALLATION_DIRS=	${SOYDIR}

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		SOYDIR=${SOYDIR}

post-extract:
.for i in admin app common license soycms
	${FIND} ${WRKSRC}/${i} -type f | xargs ${CHMOD} -x
.endfor

do-install:
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${SOYDIR}

.include "../../lang/php/json.mk"
.include "../../mk/bsd.pkg.mk"
