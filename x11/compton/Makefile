# $NetBSD: Makefile,v 1.3 2016/03/12 21:53:39 tnn Exp $

GITHUB_PROJECT=	compton
GITHUB_TAG=	d7f95b56b176281bfb252c54defef48c9cd1f4e1
DISTNAME=	compton-20150920
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=chjj/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chjj/compton
COMMENT=	Configurable compositing manager for X11
LICENSE=	mit

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=	gmake pkg-config
NO_CONFIGURE=	yes
BUILD_TARGET=	compton docs
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	COMPTON_VERSION=git-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	share/examples/compton

post-install:
	${INSTALL_DATA} ${WRKSRC}/compton.sample.conf \
		${DESTDIR}${PREFIX}/share/examples/compton

.include "../../devel/libconfig/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
