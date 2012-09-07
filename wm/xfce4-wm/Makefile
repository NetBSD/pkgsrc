# $NetBSD: Makefile,v 1.41 2012/09/07 19:17:39 adam Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfwm4-${XFCE4_VERSION}
PKGNAME=	xfce4-wm-${XFCE4_VERSION}
PKGREVISION=	11
CATEGORIES=	wm
COMMENT=	Xfce window manager

MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${PREFIX}/share/themes/Default
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/doc
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/C ${PREFIX}/share/xfce4/doc/C/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/fr ${PREFIX}/share/xfce4/doc/fr/images
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/it ${PREFIX}/share/xfce4/doc/it/images

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/xfconf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
