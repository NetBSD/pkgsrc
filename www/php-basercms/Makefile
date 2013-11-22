# $NetBSD: Makefile,v 1.1 2013/11/22 14:35:56 ryoon Exp $

DISTNAME=	basercms-2.1.2
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	-http://basercms.net/packages/download/basercms/2.1.2
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://basercms.net/packages/download/basercms/
COMMENT=	Easy to use Content Management System for Japan/Japanese
LICENSE=	mit

DEPENDS+=       ${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd

WRKSRC=			${WRKDIR}/basercms
USE_LANGUAGES=		# none

USE_TOOLS+=	pax

NO_BUILD=	yes

CHECK_INTERPRETER_SKIP+=	share/basercms/cake/console/cake.php
CHECK_INTERPRETER_SKIP+=	share/basercms/cake/console/cake

BC_DIR=		share/basercms
INSTALLATION_DIRS+=	${BC_DIR}

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		BC_DIR=${BC_DIR}

do-install:
	cd ${WRKDIR} && ${FIND} basercms -type f \! -name '*.orig' -print | \
		pax -rw -pmp ${DESTDIR}${PREFIX}/share

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
