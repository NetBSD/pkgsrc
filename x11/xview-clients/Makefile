# $NetBSD: Makefile,v 1.7 2000/08/18 22:46:53 hubertf Exp $
# $FreeBSD Id: Makefile,v 1.11 1996/11/16 10:49:52 asami Exp
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-clients-3.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org

DEPENDS=        xview-lib-3.2.1:../../x11/xview-lib

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	xview3.2p1-X11R6/clients xview3.2p1-X11R6/images
WRKSRC=      	${WRKDIR}/xview3.2p1-X11R6/clients
USE_IMAKE=	yes

post-patch:
	@${MV} ${WRKSRC}/olwm/openwin-menu-programs ${WRKSRC}/foo
	@${SED} -e 's@XXX11BASEXXX@${PREFIX}@g' < ${WRKSRC}/foo > \
		${WRKSRC}/olwm/openwin-menu-programs
	@${RM} -f ${WRKSRC}/foo

pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include "../../mk/bsd.pkg.mk"
