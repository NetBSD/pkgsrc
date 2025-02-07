# $NetBSD: Makefile,v 1.89 2025/02/07 16:18:13 pho Exp $

DISTNAME=	elinks-0.18.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rkd77/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkd77/elinks
COMMENT=	Feature-rich text mode web browser
LICENSE=	gnu-gpl-v2

CONFLICTS+=	felinks-[0-9]*
SUPERSEDES+=	felinks-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
USE_TOOLS+=		perl pkg-config

.include "../../mk/bsd.prefs.mk"

MESON_ARGS+=	-Dxbel=true	# requires textproc/expat
MESON_ARGS+=	-Dfinger=true
MESON_ARGS+=	-Dgopher=true
MESON_ARGS+=	-Dnntp=true
MESON_ARGS+=	-D88-colors=true
MESON_ARGS+=	-D256-colors=true
MESON_ARGS+=	-Dtrue-color=true
.if ${OPSYS} != "Linux"
MESON_ARGS+=	-Dgpm=false	# only makes sense on Linux
.endif
MESON_ARGS+=	-Dbzlib=true	# requires archivers/bzip2
MESON_ARGS+=	-Dbrotli=true	# requires archivers/brotli
MESON_ARGS+=	-Dzstd=true	# requires archivers/zstd
MESON_ARGS+=	-Didn=true	# requires archivers/libidn2
MESON_ARGS+=	-Dlzma=true	# requires archivers/xz
MESON_ARGS+=	-Dtre=true	# requires devel/tre
MESON_ARGS+=	-Dlibevent=true	# requires devel/libevent
MESON_ARGS+=	-Dgemini=true
MESON_ARGS+=	-Dapidoc=false	# requires devel/doxygen
MESON_ARGS+=	-Dhtmldoc=true	# requires textproc/xmlto and perl
MESON_ARGS+=	-Dpdfdoc=false	# requires textproc/dblatex
MESON_ARGS+=	-Dlibcss=true	# requires textproc/libcss and textproc/libdom
MESON_ARGS+=	-Dlibsixel=true	# requires graphics/libsixel
MESON_ARGS+=	-Dlibcurl=true	# requires www/curl
MESON_ARGS+=	-Dsftp=true	# requires www/curl

REPLACE_PERL+=	doc/tools/help2xml

.include "options.mk"

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

.include "../../textproc/expat/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.0
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/tre/buildlink3.mk"
.include "../../textproc/libcss/buildlink3.mk"
.include "../../textproc/libdom/buildlink3.mk"
.include "../../graphics/libsixel/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
