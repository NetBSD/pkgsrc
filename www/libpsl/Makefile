# $NetBSD: Makefile,v 1.7 2020/02/24 19:46:23 adam Exp $

DISTNAME=	libpsl-0.21.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rockdaboot/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rockdaboot/libpsl/
COMMENT=	Library to handle the Public Suffix List
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--enable-runtime=libicu
PKGCONFIG_OVERRIDE+=	libpsl.pc.in
TEST_TARGET=		check

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON=		src/psl-make-dafsa

.include "../../lang/python/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
