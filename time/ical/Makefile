# $NetBSD: Makefile,v 1.37 2018/11/08 05:32:23 markd Exp $

DISTNAME=	ical-3.0.3
CATEGORIES=	time
MASTER_SITES=	https://launchpad.net/ical-tcl/3.x/${PKGVERSION_NOREV}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/ical-tcl/
COMMENT=	Calendar application

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX} \
		--with-tclconfig=${BUILDLINK_PREFIX.tcl}/lib \
		--with-tclsh=${BUILDLINK_PREFIX.tcl}/bin/tclsh \
		--with-tkconfig=${BUILDLINK_PREFIX.tk}/lib

CPPFLAGS+=	-DUSE_INTERP_RESULT

USE_TOOLS+=	gmake gsed

PLIST_SUBST+=	PKGVERSION=${PKGVERSION_NOREV}

post-configure:
	${TOUCH} ${WRKDIR}/${DISTNAME}/Makefile \
	         ${WRKDIR}/${DISTNAME}/calendar/Makefile \
	         ${WRKDIR}/${DISTNAME}/time/Makefile

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
