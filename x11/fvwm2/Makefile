# $NetBSD: Makefile,v 1.8 1998/04/20 11:56:34 frueauf Exp $
# FreeBSD Id: Makefile,v 1.12 1997/10/11 10:42:43 jkh Exp
#

DISTNAME=	fvwm-2.0.46
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/fvwm-users-jp/kits/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/fvwm-users-jp/kits/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fvwm-users-jp-kits.97Oct04.tar.gz

MAINTAINER=	packages@netbsd.org

LIB_DEPENDS=	Xpm.4.:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	xpmroot:${PORTSDIR}/x11/xpmroot

USE_IMAKE=	yes
CAT1= 		FvwmAudio.0 FvwmAuto.0 FvwmBacker.0 FvwmBanner.0 \
		FvwmButtons.0 FvwmCascade.0 FvwmCpp.0 FvwmForm.0 \
		FvwmIconBox.0 FvwmIconMan.0 FvwmIdent.0 FvwmM4.0 FvwmPager.0 \
		FvwmSave.0 FvwmSaveDesk.0 FvwmScroll.0 FvwmTalk.0 FvwmTile.0 \
		FvwmWinList.0 fvwm2.0

# filenames.
PATCH_FIXIT=	kits/patch/fix-2.0.46
PATCH_I18N=	kits/patch/PATCH.I18N
USE_PATCHFILES=	${PATCH_FIXIT} ${PATCH_I18N}

pre-patch:
	@for i in ${USE_PATCHFILES}; do \
		${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/$$i; \
	 done;

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${WRKSRC}/icons/*.xbm \
			${WRKSRC}/icons/*.bitmap ${WRKSRC}/icons/*.icon \
		${PREFIX}/lib/X11/fvwm2/pixmaps
	@${CAT} ${PKGDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
