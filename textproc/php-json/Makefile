# $NetBSD: Makefile,v 1.5 2017/12/13 11:42:41 jperkin Exp $

MODNAME=		json
PKGREVISION=		1
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
