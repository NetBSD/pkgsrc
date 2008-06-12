# $NetBSD: Makefile,v 1.6 2008/06/12 02:14:51 joerg Exp $

MODNAME=		pspell
CATEGORIES+=		textproc
COMMENT=		PHP extension for pspell support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pspell-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.aspell}

.include "../../lang/php/ext.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
