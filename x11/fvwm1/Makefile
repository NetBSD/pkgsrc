# New ports collection makefile for:	fvwm (version 1)
# Version required:	1.24r
# Date created:		17 March 1997
# Whom:			cjs@netbsd.org
#
# $NetBSD: Makefile,v 1.3 1998/03/18 18:46:40 cjs Exp $
# FreeBSD Id: Makefile,v 1.12 1997/10/11 10:42:43 jkh Exp
#

DISTNAME=	fvwm-1.24r
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/

MAINTAINER=	cjs@netbsd.org

LIB_DEPENDS=	Xpm.4.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
XMKMF=		xmkmf && make Makefiles	# drop -a because we have no `depends' target

CAT1= 		FvwmAudio.0 FvwmAuto.0 FvwmBacker.0 FvwmBanner.0 \
		FvwmIconBox.0 FvwmIdent.0 FvwmPager.0 \
		FvwmSave.0 FvwmSaveDesk.0 FvwmScroll.0 \
		FvwmWinList.0 fvwm.0 xpmroot.0

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fvwm/pixmaps
	@${MKDIR} ${PREFIX}/lib/X11/fvwm/bitmaps
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xpm \
		${PREFIX}/lib/X11/fvwm/pixmaps
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xbm \
		${WRKSRC}/fvwm_icons/*.bitmap ${WRKSRC}/fvwm_icons/*.icon \
		${PREFIX}/lib/X11/fvwm/bitmaps

.include <bsd.port.mk>
