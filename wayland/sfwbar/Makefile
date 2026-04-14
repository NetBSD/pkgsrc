# $NetBSD: Makefile,v 1.1 2026/04/14 12:53:47 kikadf Exp $

DISTNAME=	sfwbar-1.0_beta17
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=LBCrion/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/LBCrion/sfwbar/
COMMENT=	S* Floating Window Bar for wayland compositors
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/sfwbar

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD"
MESON_ARGS+=	-Dbsdctl=enabled
.else
MESON_ARGS+=	-Dbsdctl=disabled
.endif
MESON_ARGS+=	-Dpulse=disabled
MESON_ARGS+=	-Dpipewire=disabled
MESON_ARGS+=	-Dalsa=disabled
MESON_ARGS+=	-Diwd=disabled
MESON_ARGS+=	-Dnm=disabled
MESON_ARGS+=	-Dxkb=enabled
MESON_ARGS+=	-Ddbus=enabled

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/sfwbar/memory.source.orig


.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wayland/gtk-layer-shell/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
