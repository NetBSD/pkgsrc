# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:06 joerg Exp $

MODNAME=		wddx
PKGREVISION=		2
CATEGORIES+=		textproc
COMMENT=		PHP extension for WDDX support


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.expat}

.include "../../lang/php/ext.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
