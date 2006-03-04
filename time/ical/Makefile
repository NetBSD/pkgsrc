# $NetBSD: Makefile,v 1.19 2006/03/04 21:30:52 jlam Exp $

DISTNAME=	ical-2.3.1
PKGREVISION=	2
CATEGORIES=	time
MASTER_SITES=	http://www.annexia.org/_file/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.annexia.org/freeware/ical
COMMENT=	Calendar application

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX:Q} \
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
