# $NetBSD: Makefile,v 1.2 2000/09/01 17:26:54 jwise Exp $
#

DISTNAME=	BLT2.4o
PKGNAME=	blt-2.4o
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tcltk.com/aa004735/pub/blt/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.tcltk.com/blt/index.html

DEPENDS+=	tk-8.3.2:../../x11/tk

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tk=${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/blt2.4o

.include "../../mk/bsd.pkg.mk"
