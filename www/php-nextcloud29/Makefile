# $NetBSD: Makefile,v 1.2 2025/02/08 04:04:41 taca Exp $
#

# The nextcloud update process only works from one version to the
# next; one cannot update e.g from 16 to 18.  It is a requirement for
# stable branch users, if they update every stable branch, to have
# automatic updates work.  Therefore a major update can only be
# committed to pkgsrc-current if it is one higher than the major
# version in the previous stable branch.  As an example, if 2020Q1
# contained 18.0.2, then during April to June it is ok to update to
# later 18.x.y, to 19.0.0, and to later 19.x.y, but it is not ok to
# update to 20.
DISTNAME=	nextcloud-29.0.8
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://download.nextcloud.com/server/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://nextcloud.com/
COMMENT=	File sharing web service server, 29 release branch
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=${PHP_BASE_VERS}:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=${PHP_BASE_VERS}:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=${PHP_BASE_VERS}:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=${PHP_BASE_VERS}:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-sodium>=${PHP_BASE_VERS}:../../security/php-sodium
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=${PHP_BASE_VERS}:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-sysvsem>=${PHP_BASE_VERS}:../../devel/php-sysvsem

.include "options.mk"

WRKSRC=		${WRKDIR}/nextcloud
USE_LANGUAGES=	# none

NO_BUILD=	yes

USE_TOOLS+=	bash:run pax perl:run

NC_DIR=		share/nextcloud
INSTALLATION_DIRS=	${NC_DIR}

# Nextcloud "documents" in lib/versioncheck.php that:
#   nextcloud requires at least PHP 8.0
#   nextcloud it not compatible with PHP 8.3 or higher
PHP_VERSIONS_INCOMPATIBLE=	56 74

# for php interpreter
CHECK_INTERPRETER_SKIP+=	${NC_DIR}/3rdparty/doctrine/dbal/bin/doctrine-dbal
CHECK_INTERPRETER_SKIP+=	${NC_DIR}/3rdparty/dompdf/load_font.php
CHECK_INTERPRETER_SKIP+=	${NC_DIR}/3rdparty/phpdocx/pdf/load_font.php
CHECK_INTERPRETER_SKIP+=	${NC_DIR}/3rdparty/sabre/vobject/bin/*
CHECK_INTERPRETER_SKIP+=	${NC_DIR}/apps/contacts/vendor/blueimp-tmpl/js/compile.js
CHECK_INTERPRETER_SKIP+=	${NC_DIR}/occ

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	nginx
APACHE_GROUP?=	nginx
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		NC_DIR=${NC_DIR}

do-install:
	cd ${WRKDIR} && ${FIND} nextcloud -type f \! -name '*.orig' -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share

.include "../../lang/php/json.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
