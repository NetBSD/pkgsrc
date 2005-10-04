# $NetBSD: Makefile,v 1.45 2005/10/04 01:47:32 minskim Exp $
#

.include "Makefile.common"

COMMENT=		GTK-based implementation of the wxWidgets GUI library

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
