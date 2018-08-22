# $NetBSD: Makefile,v 1.45 2018/08/22 09:47:21 wiz Exp $

PKGREVISION= 10
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	4.12.1
DISTNAME=	orage-${VERSION}
PKGNAME=	xfce4-orage-${VERSION}
CATEGORIES=	time
MASTER_SITES=	http://archive.xfce.org/src/apps/orage/4.12/

HOMEPAGE=	http://www.kolumbus.fi/~w408237/orage/
COMMENT=	Xfce time managing application

CONFIGURE_ARGS+=	--disable-libxfce4mcs

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

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
