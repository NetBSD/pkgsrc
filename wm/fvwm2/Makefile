# $NetBSD: Makefile,v 1.1.1.1 2000/12/12 02:03:48 wiz Exp $
# FreeBSD Id: Makefile,v 1.12 1997/10/11 10:42:43 jkh Exp
#

DISTNAME=	fvwm-2.2.2
PKGNAME=	${DISTNAME:S/fvwm/fvwm2/}
CATEGORIES=	x11 wm
MASTER_SITES=	ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/fvwm-users-jp/kits/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/fvwm-users-jp/kits/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fvwm.org/

DEPENDS+=	xpmroot-2.*:../../x11/xpmroot
DEPENDS+=	readline-*:../../devel/readline
DEPENDS+=	rplay-3.*:../../audio/rplay

CONFLICTS=	fvwm-2.*

USE_X11BASE=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--enable-extras
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/lib/X11/fvwm2
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/lib/X11
CONFIGURE_ARGS+=	--with-xpm-includes=${XPMDIR}/include
CONFIGURE_ARGS+=	--with-readline-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-rplay-includes=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-iconpath=${PREFIX}/lib/X11/fvwm2/pixmaps:${X11ROOT}/include/bitmaps:${X11ROOT}/include/pixmaps

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} \
		${WRKSRC}/icons/*.xpm \
		${WRKSRC}/icons/*.xbm \
		${WRKSRC}/icons/*.bitmap \
		${WRKSRC}/icons/*.icon \
		${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fvwm2
	${INSTALL_DATA} \
		${WRKSRC}/sample.fvwmrc/decor_examples \
		${WRKSRC}/sample.fvwmrc/system.fvwm2rc-sample-* \
		${PREFIX}/lib/X11/fvwm2
	${INSTALL_DATA} \
		${WRKSRC}/sample.fvwmrc/system.fvwm2rc \
		${PREFIX}/lib/X11/fvwm2/system.fvwm2rc.example
	if [ ! -f ${PREFIX}/lib/X11/fvwm2/system.fvwm2rc ]; then \
		${INSTALL_DATA} \
			${PREFIX}/lib/X11/fvwm2/system.fvwm2rc.example \
			${PREFIX}/lib/X11/fvwm2/system.fvwm2rc ; \
	fi

.include "../../mk/bsd.pkg.mk"
