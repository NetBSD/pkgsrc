# $NetBSD: Makefile,v 1.10 2000/07/22 10:05:47 jlam Exp $
#

DISTNAME=       fvwm-${PKG_VERSION}
PKGNAME=	xpmroot-${PKG_VERSION}
PKG_VERSION=	2.2.2
CATEGORIES=	x11
MASTER_SITES=   ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/fvwm-users-jp/kits/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/fvwm-users-jp/kits/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.fvwm.org/xpmroot.html

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11BASE=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}/utils

EVAL_PREFIX=	XPMDIR=xpm

MAKE_ENV+=	INSTALL_PROGRAM='${INSTALL_PROGRAM}'
MAKE_ENV+=	INSTALL_MAN='${INSTALL_MAN}'
MAKE_ENV+=	VERSION=${PKG_VERSION}
MAKE_ENV+=	XPMDIR=${XPMDIR}

.include "../../mk/bsd.pkg.mk"
