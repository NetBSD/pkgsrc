# $NetBSD: Makefile,v 1.58 2024/05/29 16:35:07 adam Exp $

PKGREVISION= 11
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-applets-${VERSION:R}.1
CATEGORIES=	x11

COMMENT=	MATE panel applets

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/mate-applets
CONFIGURE_ARGS+=	--without-nl

.include "../../mk/bsd.prefs.mk"

# cpufreq has been retained (including in PLIST entries) in case it's
# relevant for Linux (not tested, would require tweaks here) or someone
# wants to try resurrecting it for NetBSD.
PLIST_VARS=		batt cpufreq

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
.include "../../devel/libwnck3/buildlink3.mk"
# XXX The charpick applet includes optional gucharmap support, but the version
# presently in pkgsrc (2.32.1) is too old to be accepted, so its presence is
# ignored.
#.include "../../fonts/gucharmap/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
