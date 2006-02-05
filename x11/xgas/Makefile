# $NetBSD: Makefile,v 1.12 2006/02/05 23:11:47 joerg Exp $

DISTNAME=	xgas
PKGNAME=        xgas-1.0
PKGREVISION=	2
CATEGORIES=     x11
MASTER_SITES=   ftp://ftp.tut.ac.jp/.h3/X11/X11R6/contrib/programs/

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp
COMMENT=	Animated simulation of an ideal gas

USE_IMAKE=      yes

post-install:
	@${CHMOD} 755 ${PREFIX}/bin/xgas
	@${CHOWN} bin:bin ${PREFIX}/bin/xgas

.include "../../mk/bsd.pkg.mk"
