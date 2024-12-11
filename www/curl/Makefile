# $NetBSD: Makefile,v 1.291 2024/12/11 12:02:21 ryoon Exp $

.include "Makefile.common"
PKGREVISION=	1

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
