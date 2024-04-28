# $NetBSD: Makefile,v 1.15 2024/04/28 10:06:35 wiz Exp $

MODNAME=		enchant
CATEGORIES+=		textproc
COMMENT=		PHP extension for ENCHANT (spelling) support
PKGREVISION=		3

CONFIGURE_ARGS+=	--with-enchant=shared,${BUILDLINK_PREFIX.enchant2}

USE_PHP_EXT_PATCHES=	yes

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../lang/php/ext.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
