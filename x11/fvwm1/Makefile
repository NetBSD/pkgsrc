# $NetBSD: Makefile,v 1.17 1999/03/01 23:09:12 tron Exp $
# FreeBSD Id: Makefile,v 1.12 1997/10/11 10:42:43 jkh Exp
#

DISTNAME=	fvwm-1.24r
PKGNAME=	${DISTNAME:S/fvwm/fvwm1/}
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.hpc.uh.edu/fvwm/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS=	xpmroot-2.2:../../x11/xpmroot

CONFLICTS=	fvwm-1.*

USE_IMAKE=	yes
# drop -a because we have no `depends' target
XMKMF=		${SH} -c "xmkmf && make Makefiles"

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

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fvwm/pixmaps
	@${MKDIR} ${PREFIX}/lib/X11/fvwm/bitmaps
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xpm \
		${PREFIX}/lib/X11/fvwm/pixmaps
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xbm \
		${WRKSRC}/fvwm_icons/*.bitmap ${WRKSRC}/fvwm_icons/*.icon \
		${PREFIX}/lib/X11/fvwm/bitmaps

.include "../../mk/bsd.pkg.mk"
