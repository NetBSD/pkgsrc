# $NetBSD: Makefile,v 1.10 2003/12/29 12:05:20 xtraeme Exp $
#

DISTNAME=		gnome-applets-2.4.1
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-applets/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 panel applets

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/gnome-applets
CONF_FILES=		${EGDIR}/sound/events/mailcheck.soundlist \
			${PKG_SYSCONFDIR}/sound/events/mailcheck.soundlist

GCONF2_SCHEMAS=		cdplayer.schemas
GCONF2_SCHEMAS+=	charpick.schemas
GCONF2_SCHEMAS+=	drivemount.schemas
GCONF2_SCHEMAS+=	geyes.schemas
GCONF2_SCHEMAS+=	gkb.schemas
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

.if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
GCONF2_SCHEMAS+=	battstat.schemas
PLIST_SUBST+=		BATTSTAT=""
CONF_FILES+=		${EGDIR}/sound/events/batt_stat_applet.soundlist \
			${PKG_SYSCONFDIR}/sound/events/battstat_applet.soundlist
.else
PLIST_SUBST+=		BATTSTAT="@comment "
.endif

.include "../../devel/GConf2/schemas.mk"
INSTALL_EXTRA_TMPL+=	${FILESDIR}/install.tmpl

.include "../../devel/gail/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgtop2/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-panel/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
