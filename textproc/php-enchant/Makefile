# $NetBSD: Makefile,v 1.19 2026/09/27 11:38:53 tnn Exp $

MODNAME=		enchant
PKGREVISION=		7
CATEGORIES+=		textproc
COMMENT=		PHP extension for ENCHANT (spelling) support

CONFIGURE_ARGS+=	--with-enchant=shared,${BUILDLINK_PREFIX.enchant2}

USE_PHP_EXT_PATCHES=	yes

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../lang/php/ext.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
