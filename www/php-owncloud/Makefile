# $NetBSD: Makefile,v 1.2 2011/12/18 08:38:14 ryoon Exp $
#

DISTNAME=	owncloud-2.0.1
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://owncloud.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://owncloud.org/
COMMENT=	Web services under your control
LICENSE=	gnu-agpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PHP_PKG_PREFIX}-zip>=5.2.0:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.2.0:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.2.0:../../converters/php-mbstring

.include "options.mk"

WRKSRC=		${WRKDIR}/owncloud
USE_LANGUAGES=	# none

NO_BUILD=	yes

USE_TOOLS+=	pax

OC_DIR=		share/owncloud
INSTALLATION_DIRS=	${OC_DIR}

BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		OC_DIR=${OC_DIR}

do-install:
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${OC_DIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
