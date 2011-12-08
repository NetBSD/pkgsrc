# $NetBSD: Makefile,v 1.2 2011/12/08 03:01:48 joerg Exp $
#

DISTNAME=	tiki-6.4
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/tiki-/tiki6-/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tikiwiki/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://info.tiki.org/
COMMENT=	Tiki Wiki CMS Groupware web-based application
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PHP_VERSIONS_ACCEPTED=		53

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.3.8:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=5.3.8:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.3.8:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-xmlrpc>=5.3.8:../../net/php-xmlrpc

USE_LANGUAGES=	# none
NO_BUILD=	yes

USE_TOOLS+=	pax

BUILD_DEFS+=	APACHE_GROUP APACHE_USER

TIKIDIR=		share/tiki6
INSTALLATION_DIRS=	${TIKIDIR}

FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		TIKIDIR=${TIKIDIR}

do-install:
	${RM} ${WRKSRC}/*orig
	cd ${WRKSRC} && sh setup.sh -u ${APACHE_USER} -g ${APACHE_GROUP} -n
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${TIKIDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
