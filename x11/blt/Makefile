# $NetBSD: Makefile,v 1.6 2002/09/23 22:39:22 jlam Exp $
#

DISTNAME=	BLT2.4o
PKGNAME=	blt-2.4o
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tcltk.com/aa004735/pub/blt/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.tcltk.com/blt/index.html
COMMENT=	extension to Tcl/Tk

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}/lib
CONFIGURE_ENV+=		X11BASE=${X11BASE}

WRKSRC=		${WRKDIR}/blt2.4o

.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
