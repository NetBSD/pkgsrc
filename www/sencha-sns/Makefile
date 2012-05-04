# $NetBSD: Makefile,v 1.1.1.1 2012/05/04 09:42:05 ryoon Exp $
#

DISTNAME=	sencha-sns-1.0.3
CATEGORIES=	www
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://oss.icz.co.jp/sns/
COMMENT=	Social Networking Service software that supports Timeline
LICENSE=	gnu-gpl-v2 AND mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.2.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.2.0:../../converters/php-mbstring

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none
NO_BUILD=		yes

USE_TOOLS+=		pax

BUILD_DEFS+=		APACHE_GROUP APACHE_USER

SENCHADIR=		share/sencha-sns
INSTALLATION_DIRS=	${SENCHADIR}

FILES_SUBST+=		WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
			SENCHADIR=${SENCHADIR}

REPLACE_SH=		cake/console/cake

FIND_PREFIX:=		PHPDIR=php
.include "../../mk/find-prefix.mk"

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	/usr/bin/php
REPLACE.php.new=	${PHPDIR}/bin/php
REPLACE_FILES.php=	cake/console/cake.php

do-install:
	cd ${WRKSRC} && pax -rw -pmp * .htaccess \
		${DESTDIR}${PREFIX}/${SENCHADIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
