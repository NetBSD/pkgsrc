# $NetBSD: Makefile,v 1.5 2012/02/06 12:41:44 wiz Exp $

MODNAME=		enchant
PECL_VERSION=		1.1.0
PKGREVISION=		2
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		textproc
COMMENT=		PHP extension for ENCHANT (spelling) support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-enchant=shared,${BUILDLINK_PREFIX.enchant}

BUILDLINK_API_DEPENDS.enchant+=	enchant>=1.2.4

.include "../../lang/php/ext.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
