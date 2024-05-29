# $NetBSD: Makefile,v 1.281 2024/05/29 16:34:48 adam Exp $

PKGREVISION= 1
.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
