# $NetBSD: Makefile,v 1.8 2011/04/22 13:44:51 obache Exp $

MODNAME=		pspell
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP extension for pspell support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pspell-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.aspell}

PHP_VERSION_REQD=	5

.include "../../lang/php/ext.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
