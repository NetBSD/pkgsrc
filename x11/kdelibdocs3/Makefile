# $NetBSD: Makefile,v 1.30 2005/06/07 14:24:30 markd Exp $

DISTNAME=	kdelibs-${_KDE_VERSION}
PKGNAME=	kdelibdocs-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11 devel

COMMENT=	KDE library documentation

.include "../../meta-pkgs/kde3/Makefile.kde3"

BUILD_DEPENDS+=		doxygen>=1.4.3nb1:../../devel/doxygen
BUILD_DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz
BUILD_DEPENDS+=		qt3-docs>=3.1.1:../../x11/qt3-docs

BUILD_TARGET=		apidox
INSTALL_TARGET=		install-data-local

UNLIMIT_RESOURCES+=	datasize

pre-install:
	${MV} ${PREFIX}/share/doc/kde/HTML/en/kdelibs-apidocs/common \
	${PREFIX}/share/doc/kde/HTML/en/kdelibs-apidocs/common.save

post-install:
	cd ${WRKSRC};							\
	DOCDIRS="arts dcop dnssd interfaces kabc kate kdecore kdefx kdeprint kdeui khtml kio kjs kmdi knewstuff kparts kresources kutils kwallet libkmid"; \
	for d in $${DOCDIRS}; do					\
		(cd $${d}; ${GMAKE} install-apidox);			\
	done
	${RM} ${PREFIX}/share/doc/kde/HTML/en/kdelibs-apidocs/common
	${MV} ${PREFIX}/share/doc/kde/HTML/en/kdelibs-apidocs/common.save \
	${PREFIX}/share/doc/kde/HTML/en/kdelibs-apidocs/common

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
