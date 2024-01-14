# $NetBSD: Makefile,v 1.17 2024/01/14 20:12:08 wiz Exp $

DISTNAME=	libpsl-0.21.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rockdaboot/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rockdaboot/libpsl
COMMENT=	Library to handle the Public Suffix List
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		msgfmt msgmerge xgettext
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--enable-runtime=libidn2
PKGCONFIG_OVERRIDE+=	libpsl.pc.in
TEST_TARGET=		check

PYTHON_FOR_BUILD_ONLY=	tool

REPLACE_PYTHON+=	src/psl-make-dafsa

.include "../../lang/python/tool.mk"
.include "../../lang/python/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
