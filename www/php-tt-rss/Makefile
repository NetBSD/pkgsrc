# $NetBSD: Makefile,v 1.3 2013/03/19 15:24:37 ryoon Exp $
#

TTRVER=		1.7.4
DISTNAME=	Tiny-Tiny-RSS-${TTRVER}
PKGNAME=	${PHP_PKG_PREFIX}-tt-rss-${TTRVER}
CATEGORIES=	www
MASTER_SITES=	-http://nodeload.github.com/gothfox/Tiny-Tiny-RSS/tar.gz/${TTRVER}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://tt-rss.org/
COMMENT=	Tiny Tiny RSS is an open source web-based RSS feed reader
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-json-[0-9]*:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-dom-[0-9]*:../../textproc/php-dom

.include "options.mk"

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

NO_BUILD=	yes

USE_TOOLS+=	pax

TR_DIR=		share/tt-rss
INSTALLATION_DIRS=	${TR_DIR}

CHECK_INTERPRETER_SKIP+=	share/tt-rss/lib/dojo-src/rebuild-dojo.sh
CHECK_INTERPRETER_SKIP+=	share/tt-rss/update.php
CHECK_INTERPRETER_SKIP+=	share/tt-rss/update_daemon2.php
CHECK_INTERPRETER_SKIP+=	share/tt-rss/utils/extract-i18n-js.pl

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		TR_DIR=${TR_DIR}

CONF_FILES_PERMS=	${PREFIX}/share/tt-rss/config.php-dist \
			${PREFIX}/share/tt-rss/config.php \
			${APACHE_USER} ${APACHE_GROUP} 640

do-install:
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/share/tt-rss

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
