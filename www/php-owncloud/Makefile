# $NetBSD: Makefile,v 1.41 2013/12/27 15:56:38 ryoon Exp $
#

DISTNAME=	owncloud-6.0.0a
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://download.owncloud.org/community/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://owncloud.org/
COMMENT=	Web services under your control
LICENSE=	gnu-agpl-v3

EXTRACT_USING=	bsdtar

DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.3.0:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.3.0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3.0:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.3.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.3.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.3.0:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=5.3.0:../../databases/php-pdo

.include "options.mk"

WRKSRC=		${WRKDIR}/owncloud
USE_LANGUAGES=	# none

NO_BUILD=	yes

USE_TOOLS+=	bash:run pax perl:run

OC_DIR=		share/owncloud
INSTALLATION_DIRS=	${OC_DIR}

REPLACE_BASH+=	3rdparty/doctrine/dbal/run-all.sh
REPLACE_BASH+=	apps/*/*/*
REPLACE_BASH+=	core/img/image-optimization.sh
REPLACE_BASH+=	l10n/init.sh

REPLACE_PERL+=	3rdparty/phpdocx/pdf/lib/ttf2ufm/src/*/*
REPLACE_PERL+=	3rdparty/phpdocx/pdf/lib/ttf2ufm/src/*/*/*
REPLACE_PERL+=	apps/*/*/*
REPLACE_PERL+=	l10n/l10n.pl

# for php interpreter
CHECK_INTERPRETER_SKIP+=	${OC_DIR}/3rdparty/doctrine/dbal/bin/doctrine-dbal
CHECK_INTERPRETER_SKIP+=	${OC_DIR}/3rdparty/dompdf/load_font.php
CHECK_INTERPRETER_SKIP+=	${OC_DIR}/3rdparty/phpdocx/pdf/load_font.php
CHECK_INTERPRETER_SKIP+=	${OC_DIR}/occ

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
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

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
