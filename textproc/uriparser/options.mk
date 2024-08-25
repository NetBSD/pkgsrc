# $NetBSD: options.mk,v 1.3 2024/08/25 06:19:17 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.uriparser

PKG_SUPPORTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
#
# Note that uriparser itself is only written in C.
# Minumum C++14 is required for gtest.
#
# Tests are default-off in order to help building this on systems
# with older C++ compilers.
#
TEST_TARGET=	test
CMAKE_CONFIGURE_ARGS+=	-DURIPARSER_BUILD_TESTS=ON
USE_LANGUAGES=	c c++14
.  include "../../devel/googletest/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DURIPARSER_BUILD_TESTS=OFF
.endif
