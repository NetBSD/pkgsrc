# $NetBSD: Makefile,v 1.21 2012/10/29 09:46:46 cegger Exp $

DISTNAME=	fvwm-1.24r
PKGNAME=	${DISTNAME:S/fvwm/fvwm1/}
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Virtual window manager for X
LICENSE=	gnu-gpl-v2

DEPENDS+=	xpmroot-2.*:../../x11/xpmroot

CONFLICTS=	fvwm2-* fvwm>=1

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

USE_IMAKE=	YES

post-extract:
	cd ${WRKSRC}/modules; \
	for FILE in Fvwm*/Imakefile; do \
	    ${MV} $${FILE} $${FILE}.orig; \
	    ${SED} -e 's/ComplexProgramTarget/ComplexProgramTargetNoMan/' \
	           -e 's@#ifdef AlphaArchitecture@#if defined(AlphaArchitecture) \&\& !defined(NetBSDArchitecture)@' \
		<$${FILE}.orig >$${FILE}; \
	done
	${MV} ${WRKSRC}/modules/GoodStuff/Imakefile ${WRKSRC}/modules/GoodStuff/Imakefile.orig
	${SED} -e 's@#ifdef AlphaArchitecture@#if defined(AlphaArchitecture) \&\& !defined(NetBSDArchitecture)@' \
		<${WRKSRC}/modules/GoodStuff/Imakefile.orig >${WRKSRC}/modules/GoodStuff/Imakefile

post-patch:
	cd ${WRKSRC}; \
	${MV} configure.h configure.h.old; \
	${SED} -e 's#$${PREFIX}#${PREFIX}#g' \
	  -e 's#$${X11BASE}#${X11BASE}#g' configure.h.old >configure.h; \
	${MV} sample.fvwmrc/system.fvwmrc sample.fvwmrc/system.fvwmrc.old; \
	${SED} -e 's#$${PREFIX}#${PREFIX}#g' \
	  -e 's#$${X11BASE}#${X11BASE}#g' sample.fvwmrc/system.fvwmrc.old >sample.fvwmrc/system.fvwmrc; \
	${MV} sample.fvwmrc/mwm.fvwmrc sample.fvwmrc/mwm.fvwmrc.old; \
	${SED} -e 's#$${PREFIX}#${PREFIX}#g' \
	  -e 's#$${X11BASE}#${X11BASE}#g' sample.fvwmrc/mwm.fvwmrc.old >sample.fvwmrc/mvm.fvwmrc

INSTALLATION_DIRS=	lib/X11/fvwm/pixmaps lib/X11/fvwm/bitmaps

post-install:
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xpm \
	  ${DESTDIR}${PREFIX}/lib/X11/fvwm/pixmaps
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xbm \
	  ${WRKSRC}/fvwm_icons/*.bitmap ${WRKSRC}/fvwm_icons/*.icon \
	  ${DESTDIR}${PREFIX}/lib/X11/fvwm/bitmaps

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
