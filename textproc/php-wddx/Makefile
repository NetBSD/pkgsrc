# $NetBSD: Makefile,v 1.5 2005/12/05 20:51:07 rillig Exp $

MODNAME=		wddx
CATEGORIES+=		textproc
COMMENT=		PHP extension for WDDX support


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.expat}

.include "../../lang/php/ext.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
