# $NetBSD: Makefile,v 1.6 1999/08/24 10:16:38 fredb Exp $

DISTNAME=		AfterStep-1.7.126
PKGNAME=		afterstep-1.7.137
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.afterstep.org/devel/snapshots/ \
			ftp://ftp.afterstep.org/devel/archives/1.7/ \
	ftp://ftp.digex.net/pub/X11/window-managers/afterstep/devel/snapshots/ \
	ftp://ftp.digex.net/pub/X11/window-managers/afterstep/devel/archives/1.7/
#MASTER_SITES=		ftp://ftp.afterstep.org/pub/stable/ \
#	ftp://ftp.digex.net/pub/X11/window-managers/afterstep/stable/
EXTRACT_SUFX=		.tar.bz2

PATCH_SITES=		ftp://ftp.afterstep.org/devel/patches/ \
			ftp://ftp.afterstep.org/devel/patches/contrib/ \
			ftp://ftp.afterstep.org/devel/patches/archive/ \
	ftp://ftp.digex.net/pub/X11/window-managers/afterstep/devel/patches/ \
	ftp://ftp.digex.net/pub/X11/window-managers/afterstep/devel/patches/contrib/ \
	ftp://ftp.digex.net/pub/X11/window-managers/afterstep/devel/patches/archive/
PATCHFILES=		1.7.126-01-sasha-endian_deps.patch.gz \
			1.7.126-02-allanon-security_and_avoidcover.patch.gz \
			1.7.126-03-allanon-depend.patch.gz \
			1.7.126-04-allanon-shade.patch.gz \
			1.7.126-05-jan-menu_shortcuts.patch.gz \
			1.7.126-06-alcorn-aslib_modules.patch.gz \
			1.7.126-07-tildouf_allanon-icon_titles.patch.gz \
			1.7.126-08-allanon-audit_and_wharf.patch.gz \
			1.7.126-09-sasha_allanon-gradients.patch.gz \
			1.7.126-10-sasha_allanon_tigr-pager_colors.patch.gz \
			1.7.126-11-allanon-mode_130.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		fb@enteract.com
HOMEPAGE=		http://www.afterstep.org/

DEPENDS+=		asclock-11:../../x11/asclock
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png-1.0.3:../../graphics/png
DEPENDS+=		rplay-3.2.0b6:../../audio/rplay
DEPENDS+=		xli-1.16:../../graphics/xli
DEPENDS+=		xp-1.2b10:../../x11/xp
DEPENDS+=		xpm-3.4k:../../graphics/xpm

CONFLICTS=		ascp-1.0.2

DIST_SUBDIR=		AfterStep
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_X11BASE=		yes

CONFIGURE_ARGS+=	--disable-staticlibs --with-helpcommand="xpman" \
			--with-png-includes=${LOCALBASE}/include \
			--with-png-lib=${LOCALBASE}/lib \
			--with-jpeg-includes=${LOCALBASE}/include \
			--with-jpeg-lib=${LOCALBASE}/lib
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

MESSAGE_FILE=		${WRKDIR}/MESSAGE

post-build:
	${SED} 's#@PREFIX@#${PREFIX}#g' < ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

post-configure:
	@(cd ${WRKSRC} ; ${GMAKE} config)
	${MAKE} do-configure

post-patch:
	cd ${WRKSRC} ; \
	for i in `find . -name "*.man" -print` autoconf/Makefile.common.in ; do \
	  ${MV} $$i $$i.orig ; \
	  ${SED} -e 's@/usr/local/@${PREFIX}/@g' -e 's@1x@1@g' \
	    < $$i.orig > $$i ; \
	done

.include "../../mk/bsd.pkg.mk"
