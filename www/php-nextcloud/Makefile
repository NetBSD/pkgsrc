# $NetBSD: Makefile,v 1.16 2018/08/22 09:47:57 wiz Exp $
#

DISTNAME=	nextcloud-13.0.5
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://download.nextcloud.com/server/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://nextcloud.com/
COMMENT=	File sharing web service server
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.4.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.4.0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.4.0:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.4.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.4.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.4.0:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=5.4.0:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=5.4.0:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.4.0:../../www/php-curl

.include "options.mk"

WRKSRC=		${WRKDIR}/nextcloud
USE_LANGUAGES=	# none

NO_BUILD=	yes

USE_TOOLS+=	bash:run pax perl:run

NC_DIR=		share/nextcloud
INSTALLATION_DIRS=	${NC_DIR}

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

.include "../../lang/php/phpversion.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
