# New ports collection makefile for:	Internationalized fvwm2
# Version required:	2.0.46
# Date created:		20 Jan 1996
# Whom:			peter
#
# $NetBSD: Makefile,v 1.1 1998/03/17 07:07:57 cjs Exp $
# FreeBSD Id: Makefile,v 1.12 1997/10/11 10:42:43 jkh Exp
#

DISTNAME=	fvwm-1.24r
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/

MAINTAINER=	matusita@jp.freebsd.org

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
