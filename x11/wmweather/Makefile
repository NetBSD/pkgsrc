# $NetBSD: Makefile,v 1.11 2002/10/27 13:41:25 bouyer Exp $
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

MAKE_FLAGS+=    EXTRA_LOCAL_LIBS=${EXTRA_LOCAL_LIBS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
EXTRA_LOCAL_LIBS=       -lsocket
.endif

.include "../../graphics/xpm/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
