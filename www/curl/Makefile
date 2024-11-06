# $NetBSD: Makefile,v 1.288 2024/11/06 17:05:02 leot Exp $

PKGREVISION=	1
.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
