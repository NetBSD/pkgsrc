# $NetBSD: Makefile,v 1.60 2021/12/30 15:54:22 ryoon Exp $
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
DISTNAME=	nextcloud-23.0.0
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://download.nextcloud.com/server/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://nextcloud.com/
COMMENT=	File sharing web service server
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.4.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.4.0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.4.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.4.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.4.0:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=5.4.0:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=5.4.0:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.4.0:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=5.4.0:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-sodium>=5.4.0:../../security/php-sodium

.include "options.mk"

WRKSRC=		${WRKDIR}/nextcloud
USE_LANGUAGES=	# none

NO_BUILD=	yes

USE_TOOLS+=	bash:run pax perl:run

NC_DIR=		share/nextcloud
INSTALLATION_DIRS=	${NC_DIR}

PHP_VERSIONS_INCOMPATIBLE=	56 # php-sodium

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
