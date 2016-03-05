# $NetBSD: Makefile,v 1.85 2016/03/05 11:29:47 jperkin Exp $

DISTNAME=	kdelibs-${_KDE_VERSION}
PKGNAME=	kdelibdocs-${_KDE_VERSION}
PKGREVISION=	29
CATEGORIES=	x11 devel
LICENSE=	gnu-gpl-v2

COMMENT=	KDE library documentation

.include "../../meta-pkgs/kde3/Makefile.kde3"

BUILD_DEPENDS+=		doxygen>=1.8.1.1:../../devel/doxygen
BUILD_DEPENDS+=		graphviz-[0-9]*:../../graphics/graphviz
BUILD_DEPENDS+=		qt3-docs>=3.1.1:../../x11/qt3-docs

BUILD_TARGET=		apidox
INSTALL_TARGET=		install-data-local

UNLIMIT_RESOURCES+=	datasize
CHECK_PORTABILITY_SKIP+=	kate/tests/highlight.sh

GENERATE_PLIST+=							\
	( cd ${WRKSRC}/apidocs;						\
	  ${FIND} . -type f -print | ${GREP} -v "classmap.inc" |	\
	  ${GREP} -v "^./.*/.*/.*\.tag" | ${SORT} |			\
	  ${SED} 's:^.:share/doc/kde/HTML/en/kdelibs-apidocs:' );

post-install:
	cd ${WRKSRC}/apidocs;						\
	DOCDIRS=`${FIND} . -name classmap.inc -print | ${SED} 's:/classmap.inc::'`; \
	cd ${WRKSRC};							\
	for d in $${DOCDIRS}; do					\
		(cd $${d}; ${GMAKE} DESTDIR=${DESTDIR} install-apidox);			\
	done

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
