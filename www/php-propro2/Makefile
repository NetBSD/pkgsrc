# $NetBSD: Makefile,v 1.9 2025/02/08 04:07:18 taca Exp $

MODNAME=	propro
PECL_VERSION=	2.1.0
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/propro
COMMENT=	Reusable split-off of pecl_http's property proxy API
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

PHP_VERSIONS_ACCEPTED=	74

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	${PHP_INCDIR}/ext/propro
PLIST_SRC+=		PLIST

post-install:
	${INSTALL_DATA} ${WRKSRC}/php_propro.h \
		${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/propro
	${INSTALL_DATA} ${WRKSRC}/src/php_propro_api.h \
		${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/propro

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
