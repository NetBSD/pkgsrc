# $NetBSD: Makefile,v 1.10 2011/11/01 06:02:53 sbd Exp $

DISTNAME=	gtk+-3.0.12
PKGNAME=	${DISTNAME:S/gtk/gtk3/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/3.0/ \
		${MASTER_SITE_GNOME:=sources/gtk+/3.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gtk.org/
COMMENT=	GIMP Toolkit v3 - libraries for building X11 user interfaces
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt perl pkg-config bash
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PTHREAD_AUTO_VARS=	yes

GNU_CONFIGURE=		yes
# XXX there is a subtle bashism in "configure" or a bug in NetBSD's sh
CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/libdata
# Work around build problems, disable unstable PAPI, PR #41608:
CONFIGURE_ARGS+=	--disable-papi
# XXX for now, to avoid conflict
CONFIGURE_ARGS+=	--enable-gtk2-dependency
DEPENDS+=		gtk2+-[0-9]*:../../x11/gtk2
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	gdk-3.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-3.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-3.0.pc.in
PKGCONFIG_OVERRIDE+=	gtk+-unix-print-3.0.pc.in
PKGCONFIG_OVERRIDE+=	gail-3.0-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	gail-3.0.pc.in

INSTALLATION_DIRS+=	lib/gtk-3.0/immodules
INSTALLATION_DIRS+=	lib/gtk-3.0/modules
INSTALLATION_DIRS+=	lib/gtk-3.0/3.0.0/filesystems

#REQD_DIRS+=		${PREFIX}/libdata/gtk-2.0

BUILD_DIRS=		. demos/gtk-demo

.include "../../mk/bsd.prefs.mk"

# gtk/Makefile.am hardcodes 'grep -o' so require GNU grep on platforms
# which do not have it.
.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		grep-[0-9]*:../../textproc/grep
TOOLS_PATH.grep=	${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}grep
.endif

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""

# We remove the module databases during post-install since we create them
# anew in the +INSTALL script as part of the POST-INSTALL action.
#
post-install:
	${RM} -f ${DESTDIR}${GTK3_IMMODULES_DB}

_BUILDING_GTK3=	yes
.include "modules.mk"

.include "../../databases/shared-mime-info/buildlink3.mk"
BUILDLINK_API_DEPENDS.atk+=	atk>=1.30.0
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.28.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"

.include "options.mk"

BUILDLINK_API_DEPENDS.pango+=	pango>=1.24.0
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
