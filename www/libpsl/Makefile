# $NetBSD: Makefile,v 1.22 2026/08/16 12:13:03 wiz Exp $

DISTNAME=	libpsl-0.23.3
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
USE_TOOLS+=		gmake msgfmt msgmerge pkg-config xgettext
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--enable-runtime=libidn2
# Fix for iconv detection in gettext 1.0.
CONFIGURE_ENV.Darwin=	am_cv_func_iconv_works=yes
PKGCONFIG_OVERRIDE+=	libpsl.pc.in
TEST_TARGET=		check

PYTHON_FOR_BUILD_ONLY=	tool

REPLACE_PYTHON+=	src/psl-make-dafsa

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
