# $NetBSD: Makefile,v 1.14 2012/10/25 06:56:46 asau Exp $

MODNAME=		pspell
CATEGORIES+=		textproc
COMMENT=		PHP extension for pspell support

CONFLICTS=	php-pspell-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.aspell}

.include "../../lang/php/ext.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
