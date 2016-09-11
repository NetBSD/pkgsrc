# $NetBSD: Makefile,v 1.5 2016/09/11 17:03:28 taca Exp $
#

DISTNAME=	matcha-sns-1.3.7
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://oss.icz.co.jp/sns/
COMMENT=	Social Networking Service software that supports Timeline
LICENSE=	gnu-gpl-v2 AND mit

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.2.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.2.0:../../converters/php-mbstring

PHP_VERSIONS_ACCEPTED=	56

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none
NO_BUILD=		yes

USE_TOOLS+=		pax

BUILD_DEFS+=		APACHE_GROUP APACHE_USER

SENCHADIR=		share/matcha-sns
INSTALLATION_DIRS=	${SENCHADIR}

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

FILES_SUBST+=		WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
			SENCHADIR=${SENCHADIR}

REPLACE_SH=		cake/console/cake

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	/usr/bin/php
REPLACE.php.new=	${LOCALBASE}/bin/php
REPLACE_FILES.php=	cake/console/cake.php

CONF_FILES_PERMS=	${PREFIX}/share/matcha-sns/app/config/core.php-dist \
			${PREFIX}/share/matcha-sns/app/config/core.php \
			${APACHE_USER} ${APACHE_GROUP} 640

CONF_FILES_PERMS+=	${PREFIX}/share/matcha-sns/cake/console/templates/skel/config/database.php.default \
			${PREFIX}/share/matcha-sns/cake/console/templates/skel/config/database.php \
			${APACHE_USER} ${APACHE_GROUP} 640

pre-install:
	cd ${WRKSRC} && \
	${MV} app/config/core.php app/config/core.php-dist

do-install:
	cd ${WRKSRC} && pax -rw -pmp * .htaccess \
		${DESTDIR}${PREFIX}/${SENCHADIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
