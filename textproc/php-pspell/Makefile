# $NetBSD: Makefile,v 1.1.1.1 2005/09/27 12:01:59 salo Exp $

MODNAME=		pspell
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP extension for pspell support


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.aspell}

.include "../../lang/php/ext.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
