# $NetBSD: Makefile,v 1.34 2004/10/03 00:18:32 tv Exp $
#

DISTNAME=		gnome-applets-2.8.0
PKGREVISION=		1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-applets/2.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel applets

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

PKGCONFIG_OVERRIDE+=	libgswitchit/gswitchit.pc.in

EGDIR=			${PREFIX}/share/examples/gnome-applets
CONF_FILES=		${EGDIR}/sound/events/mailcheck.soundlist \
			${PKG_SYSCONFDIR}/sound/events/mailcheck.soundlist

GCONF2_SCHEMAS=		charpick.schemas
GCONF2_SCHEMAS+=	drivemount.schemas
GCONF2_SCHEMAS+=	geyes.schemas
GCONF2_SCHEMAS+=	gkb.schemas
GCONF2_SCHEMAS+=	gswitchit.schemas
GCONF2_SCHEMAS+=	gtik.schemas
GCONF2_SCHEMAS+=	gweather.schemas
GCONF2_SCHEMAS+=	mailcheck.schemas
GCONF2_SCHEMAS+=	mini-commander.schemas
GCONF2_SCHEMAS+=	mixer.schemas
GCONF2_SCHEMAS+=	modemlights.schemas
GCONF2_SCHEMAS+=	multiload.schemas
GCONF2_SCHEMAS+=	stickynotes.schemas

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6

.if !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || \
    ${OPSYS} == "OpenBSD"
GCONF2_SCHEMAS+=	battstat.schemas
PLIST_SUBST+=		BATTSTAT=
CONF_FILES+=		${EGDIR}/sound/events/battstat_applet.soundlist \
			${PKG_SYSCONFDIR}/sound/events/battstat_applet.soundlist
.else
PLIST_SUBST+=		BATTSTAT="@comment "
.endif

PRINT_PLIST_AWK+=	/battstat/ { print "$${BATTSTAT}"$$0; next; }

.include "../../devel/GConf2/schemas.mk"

# This must come after GConf2's schemas.mk because it will modify default
# values for keys created during the registration of .schemas files.
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/libgtop2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
