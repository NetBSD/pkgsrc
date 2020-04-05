# $NetBSD: Makefile,v 1.32 2020/04/05 16:05:43 bsiegert Exp $

PYTHON_VERSIONS_ACCEPTED=	27
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-panel-${VERSION:R}.0
CATEGORIES=	x11

COMMENT=	MATE panel application

TOOL_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=		libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

PKGCONFIG_OVERRIDE+=	libmate-panel-applet/libmatepanelapplet-4.0.pc.in

CONFIGURE_ARGS+=	--with-in-process-applets=all

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/tool.mk"

.include "options.mk"

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../misc/libmateweather/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-menus/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
