# $NetBSD: Makefile,v 1.12 2024/01/17 15:05:44 gdt Exp $

# NB: Do not depend on this package directly.  Instead, use
#   .include "../../lang/php/json.mk"
# so that it is included only when needed.

MODNAME=		json
CATEGORIES+=		textproc
COMMENT=		PHP extension for JSON serialization support

USE_LANGUAGES+=		c c++
USE_TOOLS+=		yacc

TOOL_DEPENDS+=		re2c>=0.13.0.4:../../devel/re2c

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

PHP_VERSIONS_ACCEPTED=	56 74

.include "../../lang/php/ext.mk"

INSTALLATION_DIRS+=	include/php/ext/json
JSON_INCLUDES=		php_json.h
PLIST_SRC+=		${.CURDIR}/../../textproc/php-json/PLIST

MAKE_ENV+=		RE2C=re2c

post-install:
	${INSTALL_DATA} ${WRKSRC}/${JSON_INCLUDES} \
	    ${DESTDIR}${PREFIX}/include/php/ext/json/${JSON_INCLUDES}

.include "../../mk/bsd.pkg.mk"
