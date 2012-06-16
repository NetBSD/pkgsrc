# $NetBSD: Makefile,v 1.7 2012/06/16 03:02:09 taca Exp $

MODNAME=		enchant
CATEGORIES+=		textproc
COMMENT=		PHP extension for ENCHANT (spelling) support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-enchant=shared,${BUILDLINK_PREFIX.enchant}

BUILDLINK_API_DEPENDS.enchant+=	enchant>=1.2.4

.include "../../lang/php/phpversion.mk"

# PHP 5.2.x needs pecl version
.if ${PKG_PHP_VERSION} == 52
PECL_VERSION=		1.1.0
PKGREVISION=		3
PECL_LEGACY_VERSION_SCHEME=	yes
.endif

.include "../../lang/php/ext.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
