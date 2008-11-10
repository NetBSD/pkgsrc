# $NetBSD: Makefile,v 1.15 2008/11/10 17:21:39 wiz Exp $

DISTNAME=	xgas
PKGNAME=	xgas-1.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tut.ac.jp/.h3/X11/X11R6/contrib/programs/

MAINTAINER=	nakai@mlab.t.u-tokyo.ac.jp
COMMENT=	Animated simulation of an ideal gas

USE_IMAKE=	yes

post-install:
	@${CHMOD} 755 ${PREFIX}/bin/xgas
	@${CHOWN} bin:bin ${PREFIX}/bin/xgas

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
