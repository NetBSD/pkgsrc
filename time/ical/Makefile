# $NetBSD: Makefile,v 1.14 2005/04/29 19:01:33 kristerw Exp $

DISTNAME=	ical-2.3.1
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://www.annexia.org/_file/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.annexia.org/freeware/ical
COMMENT=	Calendar application

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tclconfig=${BUILDLINK_PREFIX.tcl}/lib \
		--with-tclsh=${BUILDLINK_PREFIX.tcl}/bin/tclsh \
		--with-tkconfig=${BUILDLINK_PREFIX.tk}/lib

post-configure:
	${TOUCH} ${WRKDIR}/${DISTNAME}/Makefile \
	         ${WRKDIR}/${DISTNAME}/calendar/Makefile \
	         ${WRKDIR}/${DISTNAME}/startup.tcl \
	         ${WRKDIR}/${DISTNAME}/time/Makefile

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
