# $NetBSD: options.mk,v 1.3 2020/04/30 20:31:28 nikita Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnurl
PKG_SUPPORTED_OPTIONS=	inet6 tests
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mtests)
.include "../../lang/python/pyversion.mk"
USE_TOOLS+=		perl:test
PYTHON_FOR_BUILD_ONLY=	test
TEST_DEPENDS+=	${PYPKGPREFIX}-impacket-[0-9]*:../../net/py-impacket
.endif
