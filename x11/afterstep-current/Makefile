# $NetBSD: Makefile,v 1.1.1.1 1999/07/31 10:36:45 fredb Exp $

DISTNAME=		AfterStep-1.7.111
PKGNAME=		afterstep-1.7.125
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
PATCHFILES=		1.7.111-01-allanon-frames_and_vert_text.patch.gz \
			1.7.111-02-allanon-stuff.patch.gz \
			1.7.111-03-tildouf-frames.patch.gz \
			1.7.111-04-sasha-parser_pager.patch.gz \
			1.7.111-05-allanon-sockets_and_stuff.patch.gz \
			1.7.111-06-various-sockets_and_audio.patch.gz \
			1.7.111-07-sasha-new-asetroot_module.patch.gz \
			1.7.111-08-allanon-resize_and_smartplacement.patch.gz \
			1.7.111-09-allanon-startsondesk.patch.gz \
			1.7.111-10-sasha-asetroot_tmpheap_module.patch.gz \
			1.7.111-11-sasha_pager_asetroot_more.patch.gz \
			1.7.111-12-allanon-autoreverse_and_configurenotify.patch.gz \
			1.7.111-13-sasha-gradients_winlist.patch.gz \
			1.7.111-14-sasha-asetroot.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		fb@enteract.com
HOMEPAGE=		http://www.afterstep.org/

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png-1.0.3:../../graphics/png
DEPENDS+=		rplay-3.2.0b6:../../audio/rplay
DEPENDS+=		asclock-11:../../x11/asclock
DEPENDS+=		xli-1.16:../../graphics/xli

CONFLICTS=		ascp-1.0.2

DIST_SUBDIR=		AfterStep
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
