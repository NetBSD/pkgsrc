# $NetBSD: Makefile,v 1.277 2023/11/08 13:21:17 wiz Exp $

PKGREVISION= 2
.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
