# $NetBSD: Makefile,v 1.14 2016/02/07 07:31:12 ryoon Exp $
#

DISTNAME=	concrete5.7.5.6
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/concrete5/concrete5-5/}
CATEGORIES=	www
MASTER_SITES=	http://www.concrete5.org/download_file/-/view/85780/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.concrete5.org/
COMMENT=	Open sourece Content Management System
LICENSE=	mit

DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=5.3.3:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=5.3.3:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3.3:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.3.3:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=5.3.3:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3.3:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.3.3:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.3.3:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.3.3:../../converters/php-mbstring

USE_LANGUAGES=	# none
NO_BUILD=	yes

USE_TOOLS+=	pax

BUILD_DEFS+=	APACHE_GROUP APACHE_USER

C5DIR=			share/concrete5
INSTALLATION_DIRS=	${C5DIR}

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	nginx
APACHE_GROUP?=	nginx
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		C5DIR=${C5DIR}

pre-install:
	cd ${WRKSRC} && ${FIND} . -type f -exec ${CHMOD} -x {} \;

do-install:
	cd ${WRKSRC} && ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${C5DIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${C5DIR}/packages
	${TOUCH} ${DESTDIR}${PREFIX}/${C5DIR}/packages/.keep
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${C5DIR}/application/config
	${TOUCH} ${DESTDIR}${PREFIX}/${C5DIR}/application/config/.keep
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${C5DIR}/application/files
	${TOUCH} ${DESTDIR}${PREFIX}/${C5DIR}/application/files/.keep

.include "../../lang/php/phpversion.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
