# $NetBSD: Makefile,v 1.4 2006/02/05 23:11:44 joerg Exp $
#

.include "Makefile.common"

PKGREVISION=		9
COMMENT=		GTK-based implementation of the wxWidgets GUI library
CONFLICTS+=		wxGTK<=2.4.2nb5

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
