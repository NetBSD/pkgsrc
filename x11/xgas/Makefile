# $NetBSD: Makefile,v 1.11 2005/03/24 21:13:04 wiz Exp $

DISTNAME=	xgas
PKGNAME=        xgas-1.0
PKGREVISION=	1
CATEGORIES=     x11
MASTER_SITES=   ftp://ftp.tut.ac.jp/.h3/X11/X11R6/contrib/programs/

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp
COMMENT=	Animated simulation of an ideal gas

USE_IMAKE=      yes

post-install:
	@${CHMOD} 755 ${PREFIX}/bin/xgas
	@${CHOWN} bin:bin ${PREFIX}/bin/xgas

.include "../../mk/bsd.pkg.mk"
