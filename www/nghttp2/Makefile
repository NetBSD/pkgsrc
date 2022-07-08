# $NetBSD: Makefile,v 1.76 2022/07/08 15:05:26 wiz Exp $

.include "Makefile.common"

COMMENT=	Implementation of HTTP/2 in C

# Upstream documents that c++14 is required for C++ parts of the code;
# the base package does not use C++.
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-lib-only
PKGCONFIG_OVERRIDE+=	lib/libnghttp2.pc.in
PKGCONFIG_OVERRIDE+=	src/libnghttp2_asio.pc.in

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	script/fetch-ocsp-response

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
