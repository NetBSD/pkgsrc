# $NetBSD: Makefile,v 1.1.1.1 2010/03/16 15:42:44 taca Exp $

MODNAME=		enchant
CATEGORIES+=		textproc
COMMENT=		PHP extension for ENCHANT support.

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-enchant=shared,${BUILDLINK_PREFIX.enchant}

PHP_VERSION_REQD=	53

.include "../../lang/php/ext.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
