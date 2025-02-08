# $NetBSD: Makefile,v 1.13 2025/02/08 03:20:14 taca Exp $

# NB: Do not depend on this package directly.  Instead, use
#   .include "../../lang/php/json.mk"
# so that it is included only when needed.

MODNAME=		json
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP extension for JSON serialization support

USE_LANGUAGES+=		c c++
USE_TOOLS+=		yacc

TOOL_DEPENDS+=		re2c>=0.13.0.4:../../devel/re2c

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

PHP_VERSIONS_ACCEPTED=	56 74

.include "../../lang/php/ext.mk"

INSTALLATION_DIRS+=	${PHP_INCDIR}/ext/json
JSON_INCLUDES=		php_json.h
PLIST_SRC+=		${.CURDIR}/../../textproc/php-json/PLIST

MAKE_ENV+=		RE2C=re2c

post-install:
	${INSTALL_DATA} ${WRKSRC}/${JSON_INCLUDES} \
	    ${DESTDIR}${PREFIX}/${PHP_INCDIR}/ext/json/${JSON_INCLUDES}

.include "../../mk/bsd.pkg.mk"
