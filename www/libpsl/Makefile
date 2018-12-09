# $NetBSD: Makefile,v 1.4 2018/12/09 18:52:10 adam Exp $

DISTNAME=	libpsl-0.20.2
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rockdaboot/}
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rockdaboot/libpsl/
COMMENT=	Library to handle the Public Suffix List
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

PYTHON_FOR_BUILD_ONLY=	yes
REPLACE_PYTHON=		src/psl-make-dafsa

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--enable-runtime=libicu

PKGCONFIG_OVERRIDE+=	libpsl.pc.in

TEST_TARGET=	check

.include "../../lang/python/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
