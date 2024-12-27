# $NetBSD: Makefile,v 1.43 2024/12/27 08:21:06 wiz Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	garcon-4.20.0
PKGNAME=	xfce4-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/xfce/garcon/${PKGVERSION_NOREV:R}/

HOMEPAGE=	https://wiki.xfce.org/dev/garcon
COMMENT=	Xfce menu library

PKGCONFIG_OVERRIDE=	garcon/garcon-1.pc.in
PKGCONFIG_OVERRIDE+=	garcon-gtk/garcon-gtk3-1.pc.in

EGDIR=			${XFCE4_EGBASE}
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${EGDIR} ${EGDIR}/menus ${PKG_SYSCONFDIR}/menus

CONF_FILES=		${EGDIR}/menus/xfce-applications.menu \
			${PKG_SYSCONFDIR}/menus/xfce-applications.menu

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
