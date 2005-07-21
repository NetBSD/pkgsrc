# $NetBSD: Makefile,v 1.13 2005/07/21 16:30:00 wiz Exp $

DISTNAME=		devilspie-0.10
CATEGORIES=		x11
MASTER_SITES=		http://www.burtonini.com/computing/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.burtonini.com/blog/computers/devilspie/
COMMENT=		Window-matching utility to customize window behavior

BUILD_DEPENDS+=		libxslt>=1.0:../../textproc/libxslt

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/devilspie
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/devilspie/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/devilspie
	${INSTALL_DATA} ${WRKSRC}/sample-config.xml \
		${PREFIX}/share/examples/devilspie/

.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
