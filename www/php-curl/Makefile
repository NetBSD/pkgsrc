# $NetBSD: Makefile,v 1.4 2005/01/03 15:59:12 wiz Exp $

MODNAME=		curl
PKGREVISION=		1
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
