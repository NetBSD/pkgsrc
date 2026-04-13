# $NetBSD: Makefile,v 1.1 2026/04/13 16:52:50 kikadf Exp $

DISTNAME=	xwayland-24.1.9
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_XORG:=xserver/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Server for running X clients under Wayland from modular X.org
LICENSE=	mit AND modified-bsd AND x11 # with no-advertising clause

USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MESON_ARGS+=	-Dsecure-rpc=false
.  if ${OPSYS_VERSION} < 100000
CPPFLAGS+=	-D_OPENBSD_SOURCE # reallocarray
.  endif
.endif

.include "../../devel/wayland/platform.mk"

.if empty(PLATFORM_SUPPORTS_WAYLAND:M[Yy][Ee][Ss])
PKG_SKIP_REASON+=	"Platform does not support Wayland"
.endif

post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/xorg/protocol.txt
	${RM} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/Xserver.1
	if [ -f ${DESTDIR}${PREFIX}/share/doc/xorg-server/Xserver-DTrace.xml ]; then \
		${RM} ${DESTDIR}${PREFIX}/share/doc/xorg-server/Xserver-DTrace.xml; \
	fi

.include "../../devel/input-headers/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.if ${X11_TYPE} == "modular"
.include "../../x11/libXfont2/buildlink3.mk"
.else
.include "../../graphics/freetype2/buildlink3.mk"
.endif
.include "../../x11/libxcvt/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libei/buildlink3.mk"
.include "../../x11/xkbcomp/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
