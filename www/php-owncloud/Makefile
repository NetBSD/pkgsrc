# $NetBSD: Makefile,v 1.84 2025/02/08 04:04:41 taca Exp $
#

DISTNAME=	owncloud-10.9.1
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://download.owncloud.org/community/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://owncloud.org/
COMMENT=	Web services under your control
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=${PHP_BASE_VERS}:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=${PHP_BASE_VERS}:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=${PHP_BASE_VERS}:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}:../../www/php-curl

.include "options.mk"

WRKSRC=		${WRKDIR}/owncloud
USE_LANGUAGES=	# none

NO_BUILD=	yes

USE_TOOLS+=	bash:run pax perl:run

OC_DIR=		share/owncloud
INSTALLATION_DIRS=	${OC_DIR}

# for php interpreter
CHECK_INTERPRETER_SKIP+=	${OC_DIR}/3rdparty/doctrine/dbal/bin/doctrine-dbal
CHECK_INTERPRETER_SKIP+=	${OC_DIR}/3rdparty/dompdf/load_font.php
CHECK_INTERPRETER_SKIP+=	${OC_DIR}/3rdparty/phpdocx/pdf/load_font.php
CHECK_INTERPRETER_SKIP+=	${OC_DIR}/3rdparty/sabre/vobject/bin/*
CHECK_INTERPRETER_SKIP+=	${OC_DIR}/apps/contacts/vendor/blueimp-tmpl/js/compile.js
CHECK_INTERPRETER_SKIP+=	${OC_DIR}/occ

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	nginx
APACHE_GROUP?=	nginx
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		OC_DIR=${OC_DIR}

do-install:
	cd ${WRKDIR} && ${FIND} owncloud -type f \! -name '*.orig' -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share

.include "../../lang/php/json.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
