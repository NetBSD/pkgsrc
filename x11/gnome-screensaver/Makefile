# $NetBSD: Makefile,v 1.11 2006/08/23 09:49:12 jmmv Exp $
#

DISTNAME=	gnome-screensaver-2.14.3
PKGREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-screensaver/2.14/}

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

PKGCONFIG_OVERRIDE=	data/gnome-screensaver.pc

GCONF2_SCHEMAS=		gnome-screensaver.schemas

EGDIR=			${PREFIX}/share/examples/gnome-screensaver
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}
MESSAGE_SUBST+=		EGDIR=${EGDIR:Q}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES=		${EGDIR}/xdg/menus/gnome-screensavers.menu \
			${PKG_SYSCONFDIR}/xdg/menus/gnome-screensavers.menu

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}/pam.d
	${INSTALL_DATA} ${FILESDIR}/pam-gnome-screensaver-NetBSD \
		${EGDIR}/pam.d/gnome-screensaver-NetBSD
	${INSTALL_DATA} ${WRKSRC}/data/gnome-screensaver \
		${EGDIR}/pam.d/gnome-screensaver-Linux
	${CHMOD} 04555 ${PREFIX}/libexec/gnome-screensaver-dialog

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
