# $NetBSD: Makefile,v 1.3 1998/04/22 14:22:50 agc Exp $
#

DISTNAME=	fvwm-2.0.46
PKGNAME=	xpmroot-1.01
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/

MAINTAINER=	tron@netbsd.org

DEPENDS+=	xpm-3.4j:../../graphics/xpm

USE_IMAKE=	yes
CAT1= 		xpmroot.0

WRKSRC=		${WRKDIR}/fvwm-2.0.46/xpmroot

.include "../../mk/bsd.pkg.mk"
