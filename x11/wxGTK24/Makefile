# $NetBSD: Makefile,v 1.10 2010/01/18 09:59:45 wiz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGREVISION=		15
COMMENT=		GTK-based implementation of the wxWidgets GUI library
CONFLICTS+=		wxGTK<=2.4.2nb5

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DESTDIR}${DOCDIR}/LICENSE

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
