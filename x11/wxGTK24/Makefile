# $NetBSD: Makefile,v 1.9.2.1 2010/02/28 13:15:01 spz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		16
COMMENT=		GTK-based implementation of the wxWidgets GUI library
CONFLICTS+=		wxGTK<=2.4.2nb5

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DESTDIR}${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
