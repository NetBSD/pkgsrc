# $NetBSD: Makefile,v 1.2 2012/12/24 01:40:17 ryoon Exp $
#

DISTNAME=	soycms_1.4.0a_mysql
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/_/-/:S/_mysql//}
CATEGORIES=	www
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
# http://www.soycms.net/download
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.soycms.net/
COMMENT=	Flexible and pluggable CMS
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=5.3.0:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=5.3.0:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.3.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3.0:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.3.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3.0:../../graphics/php-gd

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

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
