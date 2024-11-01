# $NetBSD: Makefile,v 1.285 2024/11/01 00:54:02 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
