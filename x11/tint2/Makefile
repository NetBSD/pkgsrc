# $NetBSD: Makefile,v 1.64 2022/08/11 05:09:33 gutteridge Exp $

DISTNAME=		tint2-v17.0.2
PKGNAME=		${DISTNAME:S/-v/-/}
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GITLAB:=o9000/}
GITLAB_PROJECT=		tint2
GITLAB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		fernandotcl@gmail.com
HOMEPAGE=		https://gitlab.com/o9000/tint2
COMMENT=		Lightweight panel/taskbar for X11
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++ # XXX CMake. pkg does not really need c++
USE_CMAKE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt msgmerge pkg-config

INSTALLATION_DIRS=	share/examples/tint2
OWN_DIRS=		${PKG_SYSCONFDIR}/xdg/tint2
CONF_FILES=		${PREFIX}/share/examples/tint2/tint2rc \
			${PKG_SYSCONFDIR}/xdg/tint2/tint2rc

CMAKE_ARGS.Linux=	-DENABLE_BATTERY=ON
CMAKE_ARGS.*=		-DENABLE_BATTERY=OFF

CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600 -D__EXTENSIONS__
CFLAGS.SunOS+=		-Du_int8_t=uint8_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

post-install:
	${INSTALL_DATA} ${WRKSRC}/themes/tint2rc \
		${DESTDIR}${PREFIX}/share/examples/tint2

.include "../../devel/cmake/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
