# $NetBSD: Makefile,v 1.49 2002/06/13 13:03:17 lukem Exp $
# FreeBSD Id: Makefile,v 1.23 1997/10/10 09:24:38 tg Exp
#

DISTNAME=       xlockmore-5.04
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/ \
		${MASTER_SITE_XCONTRIB:=applications/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.tux.org/~bagleyd/xlockmore.html
COMMENT=	Like the XLock session locker/screen saver, but with more

CHECK_MESA=	YES

.include "../../mk/bsd.prefs.mk"

.if defined(XLOCK_LIGHT)
CONFIGURE_ARGS+=--without-gltt --without-ttf --without-opengl --without-mesa \
		--without-xpm # --without-cxx XXX doesn't work
CONFIGURE_ENV+= CXX="${CC}"	# no dependency on libstdc++
.else
USE_XPM=	YES
USE_MESA=	YES
CONFIGURE_ARGS+= --with-mesagl
.endif

.if !exists(${X11BASE}/lib/libXdpms.a)
XLOCK_NO_DPMS=	YES
.endif

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
#USE_GMAKE=	yes
DEFINES=	-DDEFAULT_SOUND_DIR='\"${PREFIX}/lib/X11/xlock/sounds/\"' \
		-DDEF_MODULEPATH='\"lib/X11/xlock/modules\"'
CC+=		${DEFINES}
CXX+=		${DEFINES}

CONFIGURE_ARGS+= --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --without-gtk
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+= --enable-def_play='/usr/bin/audioplay ${PREFIX}/lib/X11/xlockmore/'
.endif

.if defined(XLOCK_NO_DPMS)
CONFIGURE_ARGS+= --without-dpms
.endif

post-patch:
		for i in xlock/resource.c ; do \
			f=${WRKSRC}/$$i ; \
			[ -f $$f.BAK ] || ${MV} $$f $$f.BAK ; \
			${SED} \
				-e 's|@PREFIX@|${PREFIX}|g' \
				<$$f.BAK >$$f ; \
		done
.if defined(XLOCK_DEFAULT_MODE) && ${XLOCK_DEFAULT_MODE} != ""
		cd ${WRKSRC}/xlock; \
			[ -f XLock.ad.BAK ] || ${MV} XLock.ad XLock.ad.BAK ; \
			${SED} \
				-e 's/^\(XLock.mode:[ 	]*\).*/\1${XLOCK_DEFAULT_MODE}/' \
				XLock.ad.BAK >XLock.ad
.endif

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/xlockmore
		${INSTALL_DATA}	\
			${WRKSRC}/sounds/thank-you.au	\
			${WRKSRC}/sounds/identify-please.au	\
			${WRKSRC}/sounds/not-programmed.au	\
			${WRKSRC}/sounds/complete.au	\
				${PREFIX}/lib/X11/xlockmore

.include "../../mk/bsd.pkg.mk"
