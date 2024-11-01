# $NetBSD: Makefile,v 1.286 2024/11/01 12:54:49 wiz Exp $

PKGREVISION= 2
.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
