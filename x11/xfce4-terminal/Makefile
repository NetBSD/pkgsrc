# $NetBSD: Makefile,v 1.94 2026/01/27 08:41:08 wiz Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-terminal-1.1.5
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-terminal/1.1/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	https://docs.xfce.org/apps/terminal/start
COMMENT=	Xfce terminal emulator

USE_TOOLS+=	autoconf automake autoreconf

TOOL_DEPENDS+=	xfce4-dev-tools>=4.20.0:../../devel/xfce4-dev-tools

CONFIGURE_ARGS+=	--enable-maintainer-mode

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/vte3/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
