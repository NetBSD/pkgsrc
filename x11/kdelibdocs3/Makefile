# $NetBSD: Makefile,v 1.24 2004/10/13 11:55:51 markd Exp $

DISTNAME=	kdelibs-3.3.1
PKGNAME=	kdelibdocs-3.3.1
CATEGORIES=	x11 devel

COMMENT=	KDE library documentation

.include "../../meta-pkgs/kde3/Makefile.kde3"

BUILD_DEPENDS+=		doxygen>=1.3.5nb2:../../devel/doxygen
BUILD_DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz
BUILD_DEPENDS+=		qt3-docs>=3.1.1:../../x11/qt3-docs

USE_BUILDLINK3=		YES
ALL_TARGET=		apidox
INSTALL_TARGET=		install-data-local

UNLIMIT_RESOURCES+=	datasize

post-install:
	cd ${WRKSRC};							\
	DOCDIRS="arts dcop interfaces kabc kate kdecore kdefx kdeprint kdeui khtml kio kjs kmdi knewstuff kparts kresources kutils kwallet libkmid"; \
	for d in $${DOCDIRS}; do					\
		(cd $${d}; ${GMAKE} install-apidox);			\
	done

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
