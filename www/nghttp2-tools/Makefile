# $NetBSD: Makefile,v 1.31 2024/05/13 14:53:31 adam Exp $

.include "../../www/nghttp2/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}

COMMENT=	Tools for nghttp2

CONFLICTS+=	nghttp2<1.53.0nb1 # share/nghttp2/fetch-ocsp-response

# The distfile contains a C library (built via www/nghttp2) and tools
# (built by this package).
USE_LANGUAGES=		c c++20
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-python-bindings
CONFIGURE_ARGS+=	--enable-app
CONFIGURE_ARGS+=	--enable-hpack-tools

GCC_REQD+=		12

INSTALL_DIRS+=		src script

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	script/fetch-ocsp-response

.include "../../devel/libev/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../net/ngtcp2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../www/nghttp3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
