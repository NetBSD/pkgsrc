# $NetBSD: Makefile,v 1.15 2012/09/07 19:17:43 adam Exp $
#

DISTNAME=	eekboard-1.0.5
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://cloud.github.com/downloads/ueno/eekboard/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	https://fedorahosted.org/eekboard/
COMMENT=	Virtual keyboard for GNOME
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config intltool msgfmt msgmerge xgettext

PKGCONFIG_OVERRIDE+=	eek/eek-0.90.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-clutter-0.90.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-gtk-0.90.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-xkb-0.90.pc.in
PKGCONFIG_OVERRIDE+=	eek/eek-xkl-0.90.pc.in
PKGCONFIG_OVERRIDE+=	eekboard/eekboard-0.90.pc.in

CONFIGURE_ARGS+=	--with-gtk=2.0
# missing introspection for GTK2
CONFIGURE_ARGS+=	--enable-introspection=no
CONFIGURE_ARGS+=	--enable-vala=no
# require clutter-gtk-1.0
CONFIGURE_ARGS+=	--enable-clutter-gtk=no
# require libcanberra-gtk3
CONFIGURE_ARGS+=	--enable-libcanberra=no

BUILD_DEFS+=		PKG_SYSCONFBASE

EXAMPLESDIR=		${PREFIX}/share/examples/eekboard

INSTALL_MAKE_FLAGS+=	sysconfdir=${EXAMPLESDIR}

MAKE_DIRS+=		${PKG_SYSCONFBASE}/xdg/autostart
CONF_FILES+=		${EXAMPLESDIR}/xdg/autostart/eekboard-autostart.desktop \
			${PKG_SYSCONFBASE}/xdg/autostart/eekboard-autostart.desktop

TEST_TARGET=		check

.include "options.mk"

.include "../../devel/glib2/schemas.mk"

.include "../../devel/at-spi2-core/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
