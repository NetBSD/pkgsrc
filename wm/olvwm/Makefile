# $NetBSD: Makefile,v 1.6 2003/03/03 03:32:34 jschauma Exp $
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

USE_BUILDLINK2=	# defined
USE_IMAKE=	# defined
USE_X11BASE=	# defined

WRKSRC=		${WRKDIR}

.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xview-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
