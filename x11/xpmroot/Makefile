# $NetBSD: Makefile,v 1.7 1999/10/07 17:42:01 tron Exp $
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

MAINTAINER=	packages@netbsd.org

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11BASE=	YES
WRKSRC=		${WRKDIR}/fvwm-${V}/utils
MAKE_ENV+=	INSTALL_PROGRAM='${INSTALL_PROGRAM}'
MAKE_ENV+=	INSTALL_MAN='${INSTALL_MAN}'
MAKE_ENV+=	VERSION=${V}

.include "../../mk/bsd.pkg.mk"
