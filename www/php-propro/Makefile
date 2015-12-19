# $NetBSD: Makefile,v 1.2 2015/12/19 14:27:15 taca Exp $

MODNAME=	propro
PECL_VERSION=	1.0.0
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

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
