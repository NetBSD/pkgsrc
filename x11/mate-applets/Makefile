# $NetBSD: Makefile,v 1.1 2016/05/21 18:49:33 youri Exp $

PKGREVISION= 1
PYTHON_VERSIONS_ACCEPTED=	27
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-applets-${MATE_VERSION}
CATEGORIES=	x11

COMMENT=	MATE panel applets

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/mate-applets

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-applets

MAKE_DIRS+=	${PKG_SYSCONFDIR}/sound/events

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS"
CONF_FILES+=	${PREFIX}/share/examples/mate-applets/sound/events/mate-battstat_applet.soundlist \
		${PKG_SYSCONFDIR}/sound/events/mate-battstat_applet.soundlist
.endif

PLIST_VARS=	batt
.if ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS"
PLIST.batt=	yes
.endif

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

REPLACE_PYTHON+=	invest-applet/invest/chart.py
REPLACE_PYTHON+=	invest-applet/invest/invest-applet.py
REPLACE_PYTHON+=	invest-applet/invest/mate-invest-chart
.include "../../lang/python/application.mk"

.include "../../x11/mate-panel/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-settings-daemon/buildlink3.mk"
.include "../../misc/libmateweather/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../fonts/gucharmap/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview2/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
