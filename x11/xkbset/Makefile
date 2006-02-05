# $NetBSD: Makefile,v 1.9 2006/02/05 23:11:47 joerg Exp $
#

DISTNAME=	xkbset-0.3
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.math.missouri.edu/~stephen/software/xkbset/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.math.missouri.edu/~stephen/software/#xkbset
COMMENT=	Manages XKB features of the X window system

USE_X11BASE=	yes
USE_TOOLS+=	perl
REPLACE_PERL=	mskacc-gui

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
