# $NetBSD: Makefile,v 1.1.1.1 2000/05/12 05:57:52 rh Exp $
#

DISTNAME=	wmWeather-1.31
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
CATEGORIES=	x11
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://nis-www.lanl.gov/~mgh/WindowMaker/DockApps.shtml

DEPENDS+=	windowmaker-*:../../x11/windowmaker

USE_PERL5=	yes
USE_X11BASE=	yes

do-configure:
	${CP} ${WRKSRC}/GrabWeather ${WRKSRC}/GrabWeather.orig
	${SED} "s:/usr/bin/perl:${LOCALBASE}/bin/perl:g" \
		<${WRKSRC}/GrabWeather.orig >${WRKSRC}/GrabWeather

.include "../../mk/bsd.pkg.mk"
