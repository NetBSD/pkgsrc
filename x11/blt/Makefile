# $NetBSD: Makefile,v 1.9 2004/01/20 12:28:26 agc Exp $
#

DISTNAME=	BLT2.4o
PKGNAME=	blt-2.4o
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tcltk.com/aa004735/pub/blt/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.tcltk.com/blt/index.html
COMMENT=	Extension to Tcl/Tk

WRKSRC=			${WRKDIR}/blt2.4o
USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ENV+=		X11BASE=${X11BASE}

.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
