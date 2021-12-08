# $NetBSD: Makefile,v 1.14 2021/12/08 16:06:45 adam Exp $

MODNAME=		enchant
CATEGORIES+=		textproc
COMMENT=		PHP extension for ENCHANT (spelling) support
PKGREVISION=		2

CONFIGURE_ARGS+=	--with-enchant=shared,${BUILDLINK_PREFIX.enchant}

USE_PHP_EXT_PATCHES=	yes

BUILDLINK_API_DEPENDS.enchant+=	enchant>=1.2.4

.include "../../lang/php/ext.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
