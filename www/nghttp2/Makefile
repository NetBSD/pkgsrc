# $NetBSD: Makefile,v 1.93 2025/02/09 00:28:21 rillig Exp $

PKGREVISION= 3
.include "Makefile.common"

COMMENT=	Implementation of HTTP/2 in C

# Upstream documents that this is a C library -- and it is.
# There is also an example program, in C++ (requiring C++14), but this
# package does not build that library.
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
GNU_CONFIGURE_ICONV=	no
CONFIGURE_ARGS+=	--enable-lib-only
PKGCONFIG_OVERRIDE+=	lib/libnghttp2.pc.in
PKGCONFIG_OVERRIDE+=	src/libnghttp2_asio.pc.in
TEST_TARGET=		check

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
