# $NetBSD: Makefile,v 1.4 2001/02/17 17:06:55 wiz Exp $
#

DISTNAME=	wmWeather-1.31
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
CATEGORIES=	x11
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml
COMMENT=	WindowMaker DockApp showing local weather conditions

DEPENDS+=	windowmaker-*:../../wm/windowmaker

USE_PERL5=	# defined
USE_X11BASE=	# defined

do-configure:
	${CP} ${WRKSRC}/GrabWeather ${WRKSRC}/GrabWeather.orig
	${SED} "s:/usr/bin/perl:${PERL5}:g" \
		<${WRKSRC}/GrabWeather.orig >${WRKSRC}/GrabWeather

.include "../../mk/bsd.pkg.mk"
