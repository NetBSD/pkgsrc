# $NetBSD: Makefile,v 1.16 2009/07/07 17:45:09 joerg Exp $

DISTNAME=	xgas
PKGNAME=	xgas-1.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tut.ac.jp/.h3/X11/X11R6/contrib/programs/

MAINTAINER=	nakai@mlab.t.u-tokyo.ac.jp
COMMENT=	Animated simulation of an ideal gas

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
