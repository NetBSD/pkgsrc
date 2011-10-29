# $NetBSD: Makefile,v 1.7 2011/10/29 13:47:03 cheusov Exp $

MODNAME=		intl
PECL_VERSION=		1.1.2
PKGREVISION=		2
CATEGORIES+=		textproc
COMMENT=		PHP extension for i18n

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_LANGUAGES+=		c c++

.include "../../lang/php/ext.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
