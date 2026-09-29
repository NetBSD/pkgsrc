# $NetBSD: Makefile,v 1.20 2026/09/29 06:07:52 wiz Exp $

MODNAME=		enchant
PKGREVISION=		8
CATEGORIES+=		textproc
COMMENT=		PHP extension for ENCHANT (spelling) support

CONFIGURE_ARGS+=	--with-enchant=shared,${BUILDLINK_PREFIX.enchant2}

USE_PHP_EXT_PATCHES=	yes

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../lang/php/ext.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
