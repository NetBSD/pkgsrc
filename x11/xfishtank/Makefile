# $NetBSD: Makefile,v 1.5 1998/04/20 11:56:36 frueauf Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/17 07:45:12 asami Exp
#

DISTNAME=		xfishtank-2.2
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=		packages@netbsd.org

USE_IMAKE=		yes
WRKSRC=			${WRKDIR}/xfishtank2.0
NO_INSTALL_MANPAGES=	yes

post-patch:
	cd ${WRKDIR}/xfishtank2.0; ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
