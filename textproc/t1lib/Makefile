# $NetBSD: Makefile,v 1.1.1.1 1998/11/05 08:26:03 garbled Exp $
#

DISTNAME=		t1lib-0.8-beta
PKGNAME=		t1lib-0.8
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.neuroinformatik.ruhr-uni-bochum.de/ini/PEOPLE/rmz/t1lib.html

BUILD_DEPENDS=		latex:../../print/teTeX

WRKSRC=			${WRKDIR}/T1-0.8-beta
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS=		--without-x

post-install:
	${MKDIR} ${LOCALBASE}/share/examples/t1lib
	${CP} ${WRKSRC}/examples/Makefile ${LOCALBASE}/share/examples/t1lib
	${CP} ${WRKSRC}/examples/t1example1.c ${LOCALBASE}/share/examples/t1lib
	${CP} ${WRKSRC}/examples/t1lib.config ${LOCALBASE}/share/examples/t1lib
	${CP} ${WRKSRC}/examples/README.t1example1 ${LOCALBASE}/share/examples/t1lib
	${CP} ${WRKSRC}/examples/FontDataBase ${LOCALBASE}/share/examples/t1lib

.include "../../mk/bsd.pkg.mk"
