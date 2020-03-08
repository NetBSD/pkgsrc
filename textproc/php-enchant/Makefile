# $NetBSD: Makefile,v 1.12 2020/03/08 16:51:29 wiz Exp $

MODNAME=		enchant
CATEGORIES+=		textproc
COMMENT=		PHP extension for ENCHANT (spelling) support
PKGREVISION=		1

CONFIGURE_ARGS+=	--with-enchant=shared,${BUILDLINK_PREFIX.enchant}

BUILDLINK_API_DEPENDS.enchant+=	enchant>=1.2.4

.include "../../lang/php/ext.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
