# $NetBSD: Makefile,v 1.37 2020/11/05 09:09:26 ryoon Exp $

PYTHON_VERSIONS_ACCEPTED=	27

PKGREVISION= 5
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-applets-${VERSION}
CATEGORIES=	x11

COMMENT=	MATE panel applets

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/mate-applets

.include "../../mk/bsd.prefs.mk"

PLIST_VARS=		batt cpufreq
.if ${OPSYS} == "NetBSD" &&  (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+=	--enable-cpufreq=yes
PLIST.cpufreq=		yes
.endif

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-applets

MAKE_DIRS+=	${PKG_SYSCONFDIR}/sound/events

.if ${OPSYS} != "Darwin" && ${OPSYS} != "SunOS"
CONF_FILES+=	${PREFIX}/share/examples/mate-applets/sound/events/mate-battstat_applet.soundlist \
		${PKG_SYSCONFDIR}/sound/events/mate-battstat_applet.soundlist
PLIST.batt=	yes
.endif

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../x11/mate-panel/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../x11/mate-settings-daemon/buildlink3.mk"
.include "../../misc/libmateweather/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck3/buildlink3.mk"
.include "../../fonts/gucharmap/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
