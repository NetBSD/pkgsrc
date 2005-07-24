# $NetBSD: Makefile,v 1.42 2005/07/24 21:14:51 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=		5
COMMENT=		GTK-based implementation of the wxWidgets GUI library

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
