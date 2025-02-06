# $NetBSD: Makefile,v 1.293 2025/02/06 14:42:51 wiz Exp $

PKGREVISION=		1

.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath+=	curl-config.in
SUBST_SED.rpath+=	-e 's!-L@libdir@!${COMPILER_RPATH_FLAG}@libdir@ -L@libdir@!'
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adding rpath to curl-config.

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
