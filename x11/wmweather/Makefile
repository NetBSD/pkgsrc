# $NetBSD: Makefile,v 1.9 2002/01/19 15:31:43 jlam Exp $
#

DISTNAME=	wmWeather-1.31
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
CATEGORIES=	x11
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	WindowMaker DockApp showing local weather conditions

USE_BUILDLINK_ONLY=	# defined
USE_X11BASE=		# defined
REPLACE_PERL=		GrabWeather

.include "../../graphics/xpm/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
