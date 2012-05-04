# $NetBSD: Makefile,v 1.2 2012/05/04 01:28:00 ryoon Exp $
#

DISTNAME=	concrete5.5.2.1
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/concrete5/concrete5-5/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=concretecms/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.concrete5.org/
COMMENT=	Open sourece Content Management System
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.2.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.2.0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.2.0:../../databases/php-mysql

USE_LANGUAGES=	# none
NO_BUILD=	yes

USE_TOOLS+=	pax

BUILD_DEFS+=	APACHE_GROUP APACHE_USER

C5DIR=			share/concrete5
INSTALLATION_DIRS=	${C5DIR}

FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		C5DIR=${C5DIR}

REPLACE_PYTHON+=	concrete/libraries/3rdparty/htmldiff.py

do-install:
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${C5DIR}

.include "../../lang/php/phpversion.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
