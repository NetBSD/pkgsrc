# $NetBSD: Makefile,v 1.1 2015/06/03 11:53:53 fhajny Exp $

DISTNAME=	nghttp2-1.0.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=tatsuhiro-t/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nghttp2.org/
COMMENT=	Implementation of HTTP/2 in C
LICENSE=	mit

GITHUB_RELEASE=	v${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

.include "options.mk"

PKGCONFIG_OVERRIDE+=	lib/libnghttp2.pc.in
PKGCONFIG_OVERRIDE+=	src/libnghttp2_asio.pc.in

CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-python-bindings

.include "../../mk/bsd.pkg.mk"
