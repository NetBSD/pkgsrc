# $NetBSD: Makefile,v 1.10 2019/10/07 09:28:13 prlw1 Exp $

DISTNAME=	compton-7.3
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=yshui/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/yshui/compton
COMMENT=	Configurable compositing manager for X11
LICENSE=	mit AND mpl-2.0

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

REPLACE_PYTHON=	bin/compton-convgen.py
EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake pkg-config
BUILD_TARGET=	compton docs
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	COMPTON_VERSION=${PKGVERSION}

# compton uses __auto_type which is only available as of GCC 4.9.
GCC_REQD+=	4.9

INSTALLATION_DIRS+=	share/examples/compton

post-install:
	${INSTALL_DATA} ${WRKSRC}/compton.sample.conf \
		${DESTDIR}${PREFIX}/share/examples/compton

.include "options.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
