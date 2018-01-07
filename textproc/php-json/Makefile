# $NetBSD: Makefile,v 1.5.2.1 2018/01/07 18:02:30 bsiegert Exp $

MODNAME=		json
CATEGORIES+=		textproc
COMMENT=		PHP extension for JSON serialization support

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"

INSTALLATION_DIRS+=	include/php/ext/json
JSON_INCLUDES=		php_json.h
PLIST_SRC+=		${.CURDIR}/../../textproc/php-json/PLIST

post-install:
	${INSTALL_DATA} ${WRKSRC}/${JSON_INCLUDES} \
	    ${DESTDIR}${PREFIX}/include/php/ext/json/${JSON_INCLUDES}

.include "../../mk/bsd.pkg.mk"
