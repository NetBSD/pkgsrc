# $NetBSD: Makefile,v 1.3 2011/04/22 13:44:51 obache Exp $

MODNAME=		enchant
PECL_VERSION=		1.1.0
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP extension for ENCHANT (spelling) support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-enchant=shared,${BUILDLINK_PREFIX.enchant}

BUILDLINK_API_DEPENDS.enchant+=	enchant>=1.2.4

.include "../../lang/php/ext.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
