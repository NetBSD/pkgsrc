# $NetBSD: Makefile,v 1.4 2005/04/11 21:47:41 tv Exp $

MODNAME=		wddx
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP extension for WDDX support


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.expat}

.include "../../lang/php/ext.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
