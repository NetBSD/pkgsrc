# $NetBSD: Makefile,v 1.9 2003/07/17 22:56:55 grant Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/17 07:45:12 asami Exp
#

DISTNAME=		xfishtank-2.2
WRKSRC=			${WRKDIR}/xfishtank2.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Make fish swim in the background of your screen

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	cd ${WRKDIR}/xfishtank2.0; ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
