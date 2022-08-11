# $NetBSD: Makefile,v 1.66 2022/08/11 05:09:21 gutteridge Exp $

VERSION=	4.16.0
DISTNAME=	orage-${VERSION}
PKGNAME=	xfce4-orage-${VERSION}
PKGREVISION=	3
CATEGORIES=	time
MASTER_SITES=	https://archive.xfce.org/src/apps/orage/${VERSION:R}/

HOMEPAGE=	https://docs.xfce.org/apps/orage/start
LICENSE=	gnu-gpl-v2
COMMENT=	Xfce time managing application

EXTRACT_SUFX=	.tar.bz2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt msgmerge perl intltool xgettext

# avoid picking up native libpopt, e.g. on Linux
CONFIGURE_ENV+=	ac_cv_lib_popt_poptGetContext=no

MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${PREFIX}/libexec/xfce4/panel-plugins
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/panel-plugins

# solaris does it differently, so help orage out a bit
.if !exists(/usr/share/zoneinfo) && exists(/usr/share/lib/zoneinfo) \
	&& exists(/usr/share/lib/zoneinfo/tab/zone_sun.tab)
SUBST_CLASSES+=		zoneinfo
SUBST_MESSAGE.zoneinfo=	Fixing up zoneinfo location
SUBST_STAGE.zoneinfo=	pre-configure
#SUBST_FILES.zoneinfo=	libical/zoneinfo/tz_convert.par	# use libical now
SUBST_FILES.zoneinfo+=	src/parameters.c src/tz_zoneinfo_read.c
SUBST_FILES.zoneinfo+=	tz_convert/tz_convert.*
SUBST_SED.zoneinfo=	-e 's|/usr/share/zoneinfo|/usr/share/lib/zoneinfo|g'
SUBST_SED.zoneinfo+=	-e 's|zone\.tab|tab/zone_sun.tab|g'
SUBST_SED.zoneinfo+=	-e 's|iso3166\.tab|tab/country.tab|g'
.endif

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.52.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.24.0
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxfce4ui+=	libxfce4ui>=4.16.0
.include "../../x11/libxfce4ui/buildlink3.mk"
BUILDLINK_API_DEPENDS.xfce4-panel+=	xfce4-panel>=4.16.0
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libical+=	libical>=3.0
.include "../../time/libical/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
