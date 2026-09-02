# $NetBSD: Makefile,v 1.309 2026/09/02 19:19:31 wiz Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath+=	curl-config.in
SUBST_SED.rpath+=	-e 's!-L@libdir@!${COMPILER_RPATH_FLAG}@libdir@ -L@libdir@!'
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adding rpath to curl-config.

SUPERSEDES+=		wcurl-[0-9]*

.include "options.mk"

# 8.22.0
# TESTDONE: 2072 tests were considered during 655 seconds.
# TESTDONE: 1623 tests out of 1623 reported OK: 100%

.include "../../mk/bsd.pkg.mk"
