# $NetBSD: Makefile,v 1.7 2011/12/26 19:05:32 ryoon Exp $
#

DISTNAME=	tiki-6.5
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME:S/tiki-/tiki6-/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tikiwiki/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://info.tiki.org/
COMMENT=	Tiki Wiki CMS Groupware web-based application
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=5.2.0:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=5.2.0:../../databases/php-mysqli
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=5.2.0:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-xmlrpc>=5.2.0:../../net/php-xmlrpc
DEPENDS+=	${PHP_PKG_PREFIX}-pear>=1.9.4:../../lang/pear

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
	${RM} ${WRKSRC}/lib/wiki-plugins/*orig
	cd ${WRKSRC} && sh setup.sh -u ${APACHE_USER} -g ${APACHE_GROUP} -n
	cd ${WRKSRC} && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${TIKIDIR}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
