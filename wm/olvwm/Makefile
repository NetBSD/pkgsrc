# $NetBSD: Makefile,v 1.16 2007/10/09 19:19:16 martti Exp $
#

DISTNAME=	olvwm4.src4
PKGNAME=	olvwm-4.4
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	http://home.nyc.rr.com/twopks/olvwm/

MAINTAINER=	w.wnuk@zodiac.mimuw.edu.pl
HOMEPAGE=	http://home.nyc.rr.com/twopks/olvwm/
COMMENT=	Open Look Virtual Window Manager

DEPENDS+=	xview-clients>=3.2.1:../../x11/xview-clients

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xview-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
