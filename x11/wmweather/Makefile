# $NetBSD: Makefile,v 1.3 2000/12/12 02:10:20 wiz Exp $
#

DISTNAME=	wmWeather-1.31
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
CATEGORIES=	x11
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml

DEPENDS+=	windowmaker-*:../../wm/windowmaker

USE_PERL5=	# defined
USE_X11BASE=	# defined

do-configure:
	${CP} ${WRKSRC}/GrabWeather ${WRKSRC}/GrabWeather.orig
	${SED} "s:/usr/bin/perl:${PERL5}:g" \
		<${WRKSRC}/GrabWeather.orig >${WRKSRC}/GrabWeather

.include "../../mk/bsd.pkg.mk"
