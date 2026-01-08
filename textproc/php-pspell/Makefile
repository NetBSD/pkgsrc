# $NetBSD: Makefile,v 1.17 2026/01/08 14:17:49 taca Exp $

MODNAME=		pspell
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP extension for pspell support

CONFLICTS=	php-pspell-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.aspell}

PHP_VERSIONS_ACCEPTED=	56 74 82 83

.include "../../lang/php/ext.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
