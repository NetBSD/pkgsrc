# $NetBSD: Makefile,v 1.16 1999/03/01 01:38:45 hubertf Exp $
# FreeBSD Id: Makefile,v 1.12 1997/10/11 10:42:43 jkh Exp
#

DISTNAME=	fvwm-2.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/fvwm-users-jp/kits/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/fvwm-users-jp/kits/
	
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.hpc.uh.edu/fvwm/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	xpmroot-2.2:../../x11/xpmroot

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-extras
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/lib/X11/fvwm2
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/lib/X11
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
