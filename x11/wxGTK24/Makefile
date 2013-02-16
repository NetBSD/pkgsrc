# $NetBSD: Makefile,v 1.27 2013/02/16 11:18:07 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=		31
COMMENT=		GTK-based implementation of the wxWidgets GUI library
CONFLICTS+=		wxGTK<=2.4.2nb5

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DESTDIR}${DOCDIR}/LICENSE

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
