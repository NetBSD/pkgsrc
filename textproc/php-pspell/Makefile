# $NetBSD: Makefile,v 1.2 2005/12/05 20:51:07 rillig Exp $

MODNAME=		pspell
CATEGORIES+=		textproc
COMMENT=		PHP extension for pspell support


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.aspell}

.include "../../lang/php/ext.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
