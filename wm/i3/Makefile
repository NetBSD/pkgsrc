# $NetBSD: Makefile,v 1.50 2022/08/09 12:08:31 jperkin Exp $

DISTNAME=	i3-4.20.1
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	https://i3wm.org/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://i3wm.org/
COMMENT=	Improved dynamic tiling window manager
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	bash pkg-config perl:run
USE_LANGUAGES=	c99

LDFLAGS.SunOS+=	-lgen -lsocket

EGDIR=		${PREFIX}/share/examples/i3
OWN_DIRS+=	${PKG_SYSCONFDIR}/i3
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/i3/config
CONF_FILES+=	${EGDIR}/config.keycodes ${PKG_SYSCONFDIR}/i3/config.keycodes

REPLACE_PERL+=	i3-dmenu-desktop
REPLACE_PERL+=	i3-migrate-config-to-v4
REPLACE_PERL+=	i3-save-tree

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${FIND} ${DESTDIR}${PREFIX} -name '*.orig' -exec ${RM} '{}' ';'

.include "../../devel/meson/build.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/yajl/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-xrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
