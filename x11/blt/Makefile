# $NetBSD: Makefile,v 1.5 2001/12/16 07:39:10 jmc Exp $
#

DISTNAME=	BLT2.4o
PKGNAME=	blt-2.4o
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tcltk.com/aa004735/pub/blt/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.tcltk.com/blt/index.html
COMMENT=	extension to Tcl/Tk

BUILD_DEPENDS+= autoconf>=2.13:../../devel/autoconf

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_DIR}/lib
CONFIGURE_ENV+=		X11BASE=${X11BASE}

WRKSRC=		${WRKDIR}/blt2.4o

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoreconf --force

.include "../../lang/tcl/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
