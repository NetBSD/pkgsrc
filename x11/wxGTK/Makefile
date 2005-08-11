# $NetBSD: Makefile,v 1.44 2005/08/11 00:47:23 dmcmahill Exp $
#

.include "Makefile.common"

PKGREVISION=	1
COMMENT=		GTK-based implementation of the wxWidgets GUI library

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
