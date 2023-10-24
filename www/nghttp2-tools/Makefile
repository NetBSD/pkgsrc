# $NetBSD: Makefile,v 1.26 2023/10/24 22:11:30 wiz Exp $

PKGREVISION= 1
.include "../../www/nghttp2/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}

COMMENT=	Tools for nghttp2

CONFLICTS+=	nghttp2<1.53.0nb1 # share/nghttp2/fetch-ocsp-response

# Upstream documents that c++14 is required for C++ parts of the code;
# the base package does not use C++.
USE_LANGUAGES=		c c++14
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-python-bindings
CONFIGURE_ARGS+=	--enable-app
CONFIGURE_ARGS+=	--enable-hpack-tools

GCC_REQD+=		6

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
