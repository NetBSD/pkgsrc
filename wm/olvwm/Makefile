# $NetBSD: Makefile,v 1.9 2004/05/01 17:57:54 snj Exp $
#

DISTNAME=	olvwm4.src4
PKGNAME=	olvwm-4.4
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.akula.com/~jadler/sdo/olvwm/

MAINTAINER=	w.wnuk@zodiac.mimuw.edu.pl
HOMEPAGE=	http://www.akula.com/~jadler/sdo/olvwm/index.html
COMMENT=	Open Look Virtual Window Manager

DEPENDS+=	xview-clients>=3.2.1:../../x11/xview-clients

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	yes
USE_IMAKE=	# defined
USE_X11BASE=	# defined

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xview-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
