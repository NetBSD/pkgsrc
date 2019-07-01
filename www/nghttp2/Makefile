# $NetBSD: Makefile,v 1.54 2019/07/01 04:07:53 ryoon Exp $

DISTNAME=	nghttp2-1.39.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=tatsuhiro-t/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nghttp2.org/
COMMENT=	Implementation of HTTP/2 in C
LICENSE=	mit

# Upstream documents that c++14 is required for C++ parts of the code;
# the base package does not use C++.
USE_LANGUAGES=		c
# Upstream documents that gcc>=6 or clang >= 6 is required, but this
# appears not to be true for the C parts.
# https://github.com/nghttp2/nghttp2/issues/1293

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-python-bindings
PKGCONFIG_OVERRIDE+=	lib/libnghttp2.pc.in
PKGCONFIG_OVERRIDE+=	src/libnghttp2_asio.pc.in

REPLACE_PYTHON+=	script/fetch-ocsp-response

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
