# $NetBSD: Makefile,v 1.6 1999/03/01 01:49:33 hubertf Exp $
#

V=		2.2
DISTNAME=       fvwm-${V}
PKGNAME=	xpmroot-${V}
CATEGORIES=	x11
MASTER_SITES=   ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/ \
                ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
                ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/fvwm-users-jp/kits/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
                ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/fvwm-users-jp/kits/

MAINTAINER=	tron@netbsd.org

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11BASE=	YES
WRKSRC=		${WRKDIR}/fvwm-${V}/utils
MAKE_ENV+=	INSTALL_PROGRAM='${INSTALL_PROGRAM}'
MAKE_ENV+=	INSTALL_MAN='${INSTALL_MAN}'
MAKE_ENV+=	VERSION=${V}

.include "../../mk/bsd.pkg.mk"
