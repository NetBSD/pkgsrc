# $NetBSD: Makefile,v 1.6 2001/08/29 22:41:31 jlam Exp $
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

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
