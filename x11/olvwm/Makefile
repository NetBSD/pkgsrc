# $NetBSD: Makefile,v 1.5 2000/10/16 06:39:27 jlam Exp $
#

DISTNAME=	olvwm4.src4
PKGNAME=	olvwm-4.4
CATEGORIES=	x11
MASTER_SITES=	http://www.akula.com/~jadler/sdo/olvwm/

MAINTAINER=	w.wnuk@zodiac.mimuw.edu.pl
HOMEPAGE=	http://www.akula.com/~jadler/sdo/olvwm/index.html

DEPENDS+=	xview-lib>=3.2.1:../xview-lib
DEPENDS+=	xview-clients>=3.2.1nb1:../xview-clients

USE_X11BASE=	# defined
USE_XPM=	# defined
USE_IMAKE=	# defined
XMKMF=		${X11PREFIX}/bin/xvmkmf -a

NO_WRKSUBDIR=	# defined

.include "../../mk/bsd.pkg.mk"
