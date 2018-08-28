# $NetBSD: Makefile,v 1.41 2018/08/28 06:37:18 adam Exp $

DISTNAME=	nghttp2-1.32.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=tatsuhiro-t/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nghttp2.org/
COMMENT=	Implementation of HTTP/2 in C
LICENSE=	mit

GITHUB_RELEASE=	v${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
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
