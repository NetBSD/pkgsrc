# $NetBSD: Makefile,v 1.11 2004/03/08 19:52:52 minskim Exp $
#

DISTNAME=	BLT2.4z
PKGNAME=	blt-2.4z
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=blt/}

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://blt.sourceforge.net/
COMMENT=	Extension to Tcl/Tk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/blt2.4z
USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ENV+=		X11BASE=${X11BASE}
MAKE_ENV+=		CP=${CP}

.include "../../lang/tcl83/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
