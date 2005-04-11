# $NetBSD: Makefile,v 1.11 2005/04/11 21:47:48 tv Exp $
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
USE_IMAKE=	yes

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xview-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
