# $NetBSD: Makefile,v 1.4 2002/01/21 20:39:21 agc Exp $
#

DISTNAME=	olvwm4.src4
PKGNAME=	olvwm-4.4
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.akula.com/~jadler/sdo/olvwm/

MAINTAINER=	w.wnuk@zodiac.mimuw.edu.pl
HOMEPAGE=	http://www.akula.com/~jadler/sdo/olvwm/index.html
COMMENT=	Open Look Virtual Window Manager

DEPENDS+=	xview-lib>=3.2.1nb1:../../x11/xview-lib
DEPENDS+=	xview-clients>=3.2.1:../../x11/xview-clients

USE_X11BASE=	# defined
USE_IMAKE=	# defined

WRKSRC=		${WRKDIR}

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
