# $NetBSD: Makefile,v 1.7 2002/06/17 08:12:36 martti Exp $
# FreeBSD Id: Makefile,v 1.12 1997/10/11 10:42:43 jkh Exp
#

DISTNAME=	fvwm-1.24r
PKGNAME=	${DISTNAME:S/fvwm/fvwm1/}
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.fvwm.org/
COMMENT=	Virtual window manager for X

DEPENDS=	xpmroot-2.*:../../x11/xpmroot

CONFLICTS=	fvwm2-*

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
	  -e 's#$${X11BASE}#${X11BASE}#g' configure.h.old >configure.h

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fvwm/pixmaps
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fvwm/bitmaps
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xpm \
	  ${PREFIX}/lib/X11/fvwm/pixmaps
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xbm \
	  ${WRKSRC}/fvwm_icons/*.bitmap ${WRKSRC}/fvwm_icons/*.icon \
	  ${PREFIX}/lib/X11/fvwm/bitmaps
	${INSTALL_MAN} ${WRKSRC}/modules/GoodStuff/GoodStuff.man \
	  ${PREFIX}/man/man1/GoodStuff.1
	${INSTALL_MAN} ${WRKSRC}/fvwm/fvwm.man ${PREFIX}/man/man1/fvwm.1

.include "../../mk/bsd.pkg.mk"
