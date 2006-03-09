# $NetBSD: Makefile,v 1.48 2006/03/09 21:04:46 jlam Exp $
#

.include "Makefile.common"

COMMENT=		GTK-based implementation of the wxWidgets GUI library
PKGREVISION=		2

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
