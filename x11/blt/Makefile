# $NetBSD: Makefile,v 1.1.1.1 2000/03/12 01:43:55 hubertf Exp $
#

DISTNAME=	BLT2.4o
PKGNAME=	blt-2.4o
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tcltk.com/aa004735/pub/blt/

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.tcltk.com/blt/index.html

DEPENDS+=	tcl-8.0.5:../../lang/tcl80
DEPENDS+=	tk-8.0.5:../../x11/tk80

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl8.0
CONFIGURE_ARGS+=	--with-tk=${LOCALBASE}/lib/tk8.0

WRKSRC=		${WRKDIR}/blt2.4o

.include "../../mk/bsd.pkg.mk"
