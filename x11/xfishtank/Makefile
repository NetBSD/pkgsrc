# $NetBSD: Makefile,v 1.8 2003/06/02 01:15:35 jschauma Exp $
# FreeBSD Id: Makefile,v 1.2 1997/06/17 07:45:12 asami Exp
#

DISTNAME=		xfishtank-2.2
WRKSRC=			${WRKDIR}/xfishtank2.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		Make fish swim in the background of your screen

USE_IMAKE=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	cd ${WRKDIR}/xfishtank2.0; ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
