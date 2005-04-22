# $NetBSD: Makefile,v 1.4.2.1 2005/04/22 14:17:32 salo Exp $

MODNAME=		curl
PKGREVISION=		# empty
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
