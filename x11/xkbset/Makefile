# $NetBSD: Makefile,v 1.7 2005/06/01 18:03:32 jlam Exp $
#

DISTNAME=	xkbset-0.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.math.missouri.edu/~stephen/software/xkbset/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.math.missouri.edu/~stephen/software/#xkbset
COMMENT=	Manages XKB features of the X window system

USE_PERL5=	build
USE_X11BASE=	yes
REPLACE_PERL=	mskacc-gui

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
