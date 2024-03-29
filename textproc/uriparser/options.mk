# $NetBSD: options.mk,v 1.2 2023/07/20 09:46:34 nia Exp $

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
CMAKE_ARGS+=	-DURIPARSER_BUILD_TESTS=ON
USE_LANGUAGES=	c c++14
.  include "../../devel/googletest/buildlink3.mk"
.else
CMAKE_ARGS+=	-DURIPARSER_BUILD_TESTS=OFF
.endif
