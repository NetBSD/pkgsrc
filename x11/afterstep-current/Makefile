# $NetBSD: Makefile,v 1.4 1999/08/07 22:33:55 fredb Exp $

DISTNAME=		AfterStep-1.7.126
PKGNAME=		afterstep-1.7.130
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
			1.7.126-04-allanon-shade.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		fb@enteract.com
HOMEPAGE=		http://www.afterstep.org/

DEPENDS+=		asclock-11:../../x11/asclock
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png-1.0.3:../../graphics/png
DEPENDS+=		rplay-3.2.0b6:../../audio/rplay
DEPENDS+=		xli-1.16:../../graphics/xli
DEPENDS+=		xpm-3.4k:../../graphics/xpm

CONFLICTS=		ascp-1.0.2

DIST_SUBDIR=		AfterStep
USE_GMAKE=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-helpcommand="xterm -e man" \
			--with-png-includes=${LOCALBASE}/include \
			--with-png-lib=${LOCALBASE}/lib \
			--with-jpeg-includes=${LOCALBASE}/include \
			--with-jpeg-lib=${LOCALBASE}/lib
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

MESSAGE_FILE=		${WRKDIR}/MESSAGE

post-build:
	${SED} 's#@PREFIX@#${PREFIX}#g' < ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

post-patch:
	for i in ` find ${WRKSRC} -name "*.man" -print `; do \
	  ${MV} $$i $$i.orig ; \
	  ${SED} -e 's@/usr/local/@${PREFIX}/@g' -e 's@1x@1@g' \
	    < $$i.orig > $$i ; \
	done

.include "../../mk/bsd.pkg.mk"
