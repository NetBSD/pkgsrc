# $NetBSD: Makefile,v 1.11 2007/01/15 18:18:44 joerg Exp $
#

DISTNAME=	xkbset-0.3
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.math.missouri.edu/~stephen/software/xkbset/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.math.missouri.edu/~stephen/software/#xkbset
COMMENT=	Manages XKB features of the X window system

USE_X11BASE=	yes
USE_TOOLS+=	perl
REPLACE_PERL=	mskacc-gui

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
