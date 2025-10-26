# $NetBSD: Makefile,v 1.3 2025/10/26 12:15:39 ryoon Exp $

PKGCONFIG_OVERRIDE+=	sentencepiece.pc.in

CMAKE_CONFIGURE_ARGS+=	-DSPM_USE_BUILTIN_PROTOBUF=TRUE
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "Makefile.common"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
