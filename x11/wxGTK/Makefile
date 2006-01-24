# $NetBSD: Makefile,v 1.46 2006/01/24 07:33:01 wiz Exp $
#

.include "Makefile.common"

COMMENT=		GTK-based implementation of the wxWidgets GUI library
PKGREVISION=		1

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
