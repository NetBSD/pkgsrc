# $NetBSD: Makefile,v 1.7 2001/10/23 13:15:10 jlam Exp $
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
USE_PERL5=		# defined
REPLACE_PERL=		GrabWeather

CPPFLAGS+=		-I${X11BASE}/include

.include "../../mk/x11.buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
