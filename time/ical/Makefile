# $NetBSD: Makefile,v 1.5 2003/06/02 01:16:21 jschauma Exp $
# $FreeBSD Id: Makefile,v 1.15 1998/02/07 22:59:16 hoek Exp
#

DISTNAME=	ical-2.2.1
CATEGORIES=	time
MASTER_SITES=	http://members.nbci.com/majahj/ical/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://members.nbci.com/majahj/ical/
COMMENT=	Calendar application

DEPENDS+=	tk>=8.3.2:../../x11/tk

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tclconfig=${PREFIX}/lib \
		--with-tclsh=${PREFIX}/bin/tclsh \
		--with-tkconfig=${PREFIX}/lib

post-configure:
	${TOUCH} ${WRKDIR}/${DISTNAME}/Makefile \
	         ${WRKDIR}/${DISTNAME}/calendar/Makefile \
	         ${WRKDIR}/${DISTNAME}/startup.tcl \
	         ${WRKDIR}/${DISTNAME}/time/Makefile

.include "../../mk/bsd.pkg.mk"
