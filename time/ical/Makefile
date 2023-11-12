# $NetBSD: Makefile,v 1.42 2023/11/12 13:23:44 wiz Exp $

DISTNAME=	ical-3.0.4
PKGREVISION=	2
CATEGORIES=	time
MASTER_SITES=	https://launchpad.net/ical-tcl/3.x/${PKGVERSION_NOREV}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/ical-tcl/
COMMENT=	Calendar application
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/ical-tcl

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
		--with-tclconfig=${BUILDLINK_PREFIX.tcl}/lib \
		--with-tclsh=${BUILDLINK_PREFIX.tcl}/bin/tclsh \
		--with-tkconfig=${BUILDLINK_PREFIX.tk}/lib

CPPFLAGS+=	-DUSE_INTERP_RESULT

USE_TOOLS+=	gmake gsed

PLIST_SUBST+=	PKGVERSION=${PKGVERSION_NOREV}

post-configure:
	${TOUCH} ${WRKSRC}/Makefile \
	         ${WRKSRC}/calendar/Makefile \
	         ${WRKSRC}/time/Makefile

.include "../../lang/tcl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
