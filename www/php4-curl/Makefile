# $NetBSD: Makefile,v 1.3 2004/03/26 02:27:58 wiz Exp $

MODNAME=		curl
PKGREVISION=		1
CATEGORIES+=		www
COMMENT=		PHP4 extension for curl functions

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
