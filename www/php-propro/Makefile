# $NetBSD: Makefile,v 1.6 2023/06/06 12:42:48 riastradh Exp $

MODNAME=	propro
PECL_VERSION=	1.0.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/propro
COMMENT=	Reusable split-off of pecl_http's property proxy API
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	56

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
