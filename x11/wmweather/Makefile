# $NetBSD: Makefile,v 1.9.2.1 2002/06/30 06:24:47 jlam Exp $
#

DISTNAME=	wmWeather-1.31
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
CATEGORIES=	x11
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	WindowMaker DockApp showing local weather conditions

USE_BUILDLINK2=	# defined
USE_X11BASE=	# defined
REPLACE_PERL=	GrabWeather

.include "../../graphics/xpm/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
