# $NetBSD: Makefile,v 1.3 2004/09/20 21:13:01 snj Exp $

DISTNAME=		devilspie-0.5.1
CATEGORIES=		x11
MASTER_SITES=		http://www.burtonini.com/computing/

MAINTAINER=		snj@NetBSD.org
HOMEPAGE=		http://www.burtonini.com/blog/computers/devilspie/
COMMENT=		Window-matching utility to customize window behavior

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/devilspie
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/devilspie/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/devilspie
	${INSTALL_DATA} ${WRKSRC}/sample-config.xml \
		${PREFIX}/share/examples/devilspie/

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
