# $NetBSD: Makefile,v 1.18 2004/03/10 22:52:59 markd Exp $

DISTNAME=	kdelibs-3.2.1
PKGNAME=	kdelibdocs-3.2.1
CATEGORIES=	x11 devel

COMMENT=	KDE library documentation

.include "../../meta-pkgs/kde3/Makefile.kde3"

BUILD_DEPENDS+=		doxygen>=1.3.5nb2:../../devel/doxygen
BUILD_DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz
BUILD_DEPENDS+=		qt3-docs>=3.1.1:../../x11/qt3-docs

USE_BUILDLINK2=		YES
ALL_TARGET=		apidox
INSTALL_TARGET=		install-data-local

post-install:
	cd ${WRKSRC};							\
	DOCDIRS="arts dcop interfaces kabc kate kdecore kdefx kdeprint kdeui khtml kio kjs kmdi kparts kresources kutils kwallet libkmid"; \
	for d in $${DOCDIRS}; do					\
		(cd $${d}; ${GMAKE} install-apidox);			\
	done

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
