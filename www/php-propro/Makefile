# $NetBSD: Makefile,v 1.3 2016/03/12 08:34:33 fhajny Exp $

MODNAME=	propro
PECL_VERSION=	1.0.2
CATEGORIES=	www

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/propro
COMMENT=	Reusable split-off of pecl_http's property proxy API
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	55 56

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	include/php/ext/propro
PLIST_SRC+=		PLIST

post-install:
	${INSTALL_DATA} ${WRKSRC}/php_propro.h \
		${DESTDIR}${PREFIX}/include/php/ext/propro
	${INSTALL_DATA} ${WRKSRC}/src/php_propro_api.h \
		${DESTDIR}${PREFIX}/include/php/ext/propro

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
