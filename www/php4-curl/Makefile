# $NetBSD: Makefile,v 1.5 2004/07/06 19:52:01 jdolecek Exp $

MODNAME=		curl
PKGREVISION=		# empty
CATEGORIES+=		www
COMMENT=		PHP4 extension for curl functions

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
