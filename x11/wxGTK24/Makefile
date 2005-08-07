# $NetBSD: Makefile,v 1.1.1.1 2005/08/07 11:27:28 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=		6
COMMENT=		GTK-based implementation of the wxWidgets GUI library
CONFLICTS+=		wxGTK<=2.4.2nb5

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
