# $NetBSD: Makefile,v 1.5 2018/12/01 13:25:51 nia Exp $

DISTNAME=	compton-4.0
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=yshui/}
GITHUB_TAG=	v4

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/chjj/compton
COMMENT=	Configurable compositing manager for X11
LICENSE=	mit AND mpl-2.0

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

EXTRACT_USING=	bsdtar
USE_TOOLS+=	gmake pkg-config
NO_CONFIGURE=	yes
BUILD_TARGET=	compton docs
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	COMPTON_VERSION=${PKGVERSION}

INSTALLATION_DIRS+=	share/examples/compton

post-install:
	${INSTALL_DATA} ${WRKSRC}/compton.sample.conf \
		${DESTDIR}${PREFIX}/share/examples/compton

.include "options.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
