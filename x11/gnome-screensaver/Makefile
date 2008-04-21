# $NetBSD: Makefile,v 1.28 2008/04/21 19:53:50 drochner Exp $
#

DISTNAME=	gnome-screensaver-2.22.2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-screensaver/2.22/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://live.gnome.org/GnomeScreensaver/
COMMENT=	Screen saver and locker for the GNOME desktop

GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.3
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_X11=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-screensaver
PKG_SUPPORTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
. include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
. include "../../mk/bsd.prefs.mk"
.  if ${OPSYS} == "NetBSD"
# needed to read shadow passwords
DEPENDS+=	pam-pwauth_suid-*:../../security/pam-pwauth_suid
.  endif
.else
CONFIGURE_ARGS+=	--disable-pam
.endif

PKGCONFIG_OVERRIDE=	data/gnome-screensaver.pc.in

GCONF_SCHEMAS=		gnome-screensaver.schemas

EGDIR=			${PREFIX}/share/examples/gnome-screensaver
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}
MESSAGE_SUBST+=		EGDIR=${EGDIR:Q}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES=		${EGDIR}/xdg/menus/gnome-screensavers.menu \
			${PKG_SYSCONFDIR}/xdg/menus/gnome-screensavers.menu

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.8.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.8.0
BUILDLINK_API_DEPENDS.libexif+=		libexif>=0.6.12
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.5.0

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}/pam.d
	${INSTALL_DATA} ${FILESDIR}/pam-gnome-screensaver-NetBSD \
		${EGDIR}/pam.d/gnome-screensaver-NetBSD
	${INSTALL_DATA} ${WRKSRC}/data/gnome-screensaver \
		${EGDIR}/pam.d/gnome-screensaver-Linux
.if empty(PKG_OPTIONS:Mpam)
	${CHMOD} 04555 ${PREFIX}/libexec/gnome-screensaver-dialog
.endif

.include "../../devel/GConf/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
