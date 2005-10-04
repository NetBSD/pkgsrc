# $NetBSD: Makefile,v 1.17 2005/10/04 16:46:23 wiz Exp $

DISTNAME=		devilspie-0.13
CATEGORIES=		x11
MASTER_SITES=		http://www.burtonini.com/computing/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.burtonini.com/blog/computers/devilspie/
COMMENT=		Window-matching utility to customize window behavior

BUILD_DEPENDS+=		libxslt>=1.0:../../textproc/libxslt

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
TEST_TARGET=		check

#LIBS+=			-lX11

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/devilspie
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/devilspie/

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
