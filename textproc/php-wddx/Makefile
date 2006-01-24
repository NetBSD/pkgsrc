# $NetBSD: Makefile,v 1.6 2006/01/24 07:32:38 wiz Exp $

MODNAME=		wddx
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP extension for WDDX support


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.expat}

.include "../../lang/php/ext.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
