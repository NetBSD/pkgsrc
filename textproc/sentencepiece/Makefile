# $NetBSD: Makefile,v 1.2 2025/08/20 11:35:13 wiz Exp $

PKGCONFIG_OVERRIDE+=	sentencepiece.pc.in

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "Makefile.common"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
