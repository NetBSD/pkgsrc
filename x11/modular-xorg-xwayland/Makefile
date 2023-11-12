# $NetBSD: Makefile,v 1.18 2023/11/12 13:24:19 wiz Exp $

DISTNAME=	xwayland-23.1.1
PKGNAME=	modular-xorg-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=xserver/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Server for running X clients under Wayland from modular X.org
LICENSE=	mit AND modified-bsd AND x11 # with no-advertising clause

USE_TOOLS+=	pkg-config

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

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../x11/libXfont2/buildlink3.mk"
.include "../../x11/libxcvt/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
