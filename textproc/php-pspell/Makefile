# $NetBSD: Makefile,v 1.10 2011/10/20 09:10:03 cheusov Exp $

MODNAME=		pspell
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP extension for pspell support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pspell-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.aspell}

PHP_VERSIONS_ACCEPTED=	53

.include "../../lang/php/ext.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
