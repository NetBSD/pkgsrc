# $NetBSD: Makefile,v 1.6 2013/07/12 10:45:05 jperkin Exp $
#

SCVER=		6.5.13
DISTNAME=	SugarCE-${SCVER}
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/SugarCE/sugarcrm/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sugarcrm/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.sugarcrm.com/
COMMENT=	Open source CRM
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/SugarCE-Full-${SCVER}
USE_LANGUAGES=	# none
NO_BUILD=	yes

DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.2.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=5.2.0:../../archivers/php-zlib
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.2.0:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=5.2.0:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=5.2.0:../../mail/php-imap
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3.0:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=5.2.0:../../www/php-curl



USE_TOOLS+=	pax

SCDIR=		share/sugercrm
INSTALLATION_DIRS=	${SCDIR}

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}

PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		SCDIR=${SCDIR}

post-extract:
	${FIND} ${WRKSRC} -type f | xargs ${CHMOD} -x

do-install:
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${SCDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
