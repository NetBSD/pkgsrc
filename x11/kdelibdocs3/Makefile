# $NetBSD: Makefile,v 1.15 2004/02/15 11:03:12 markd Exp $

DISTNAME=	kdelibs-3.2.0
PKGNAME=	kdelibdocs-3.2.0
CATEGORIES=	x11 devel

COMMENT=	KDE library documentation

.include "../../meta-pkgs/kde3/Makefile.kde3"

BUILD_DEPENDS+=		doxygen>=1.3.5nb2:../../devel/doxygen

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
