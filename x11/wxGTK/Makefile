# $NetBSD: Makefile,v 1.43 2005/08/07 11:26:17 wiz Exp $
#

.include "Makefile.common"

COMMENT=		GTK-based implementation of the wxWidgets GUI library

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
