# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:53 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1997/10/11 10:42:43 jkh Exp
#

DISTNAME=	fvwm-1.24r
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/

MAINTAINER=	cjs@netbsd.org

LIB_DEPENDS=	Xpm.4.:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	xpmroot:${PORTSDIR}/x11/xpmroot

USE_IMAKE=	yes
XMKMF=		xmkmf && make Makefiles	# drop -a because we have no `depends' target

CAT1=		GoodStuff.0 fvwm.0

post-extract:
	cd ${WRKSRC}/modules; \
	for FILE in Fvwm*/Imakefile; do \
	    ${MV} $${FILE} $${FILE}.orig; \
	    ${SED} s/ComplexProgramTarget/ComplexProgramTargetNoMan/ \
		<$${FILE}.orig >$${FILE}; \
	done

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fvwm/pixmaps
	@${MKDIR} ${PREFIX}/lib/X11/fvwm/bitmaps
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xpm \
		${PREFIX}/lib/X11/fvwm/pixmaps
	${INSTALL_DATA} ${WRKSRC}/fvwm_icons/*.xbm \
		${WRKSRC}/fvwm_icons/*.bitmap ${WRKSRC}/fvwm_icons/*.icon \
		${PREFIX}/lib/X11/fvwm/bitmaps

.include "../../mk/bsd.pkg.mk"
