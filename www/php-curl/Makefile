# $NetBSD: Makefile,v 1.7 2005/09/28 12:34:03 rillig Exp $

MODNAME=		curl
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions


CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
