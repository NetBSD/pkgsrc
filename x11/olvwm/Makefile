# $NetBSD: Makefile,v 1.3 2000/08/23 23:14:35 tron Exp $
#

DISTNAME=	olvwm4.src4
PKGNAME=	olvwm-4.4
CATEGORIES=	x11
MASTER_SITES=	http://www.akula.com/~jadler/sdo/olvwm/

MAINTAINER=	w.wnuk@zodiac.mimuw.edu.pl
HOMEPAGE=	http://www.akula.com/~jadler/sdo/olvwm/index.html

DEPENDS+=	xview-lib-3.2.*:../xview-lib
DEPENDS+=	xview-clients-3.2.*:../xview-clients

USE_X11BASE=	YES
USE_XPM=	YES
USE_IMAKE=	YES
NO_WRKSUBDIR=	YES

post-install:
	${MV} ${PREFIX}/man/cat1/olvwmrc.1 ${PREFIX}/man/man1/olvwmrc.1

.include "../../mk/bsd.pkg.mk"
