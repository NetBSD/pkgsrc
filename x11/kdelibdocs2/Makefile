# $NetBSD: Makefile,v 1.3 2001/12/04 12:36:53 skrll Exp $

DISTNAME=	kdelibs-2.2.2
PKGNAME=	${DISTNAME:S/kdelib/kdelibdoc/}
CATEGORIES=	x11 devel
COMMENT=	KDE library documentation

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=		kdoc>=2.2.2:../../textproc/kdoc2
DEPENDS+=		qt2-docs>=2.3.1:../../x11/qt2-docs

USE_X11BASE=		yes
NO_CONFIGURE=		yes

EVAL_PREFIX+=		QT2DIR=qt2
DOCINSTALLDIR=		${X11BASE}/share/doc/kde/HTML/en

do-build:
	${MKDIR} ${WRKDIR}/kdelibs
	${LOCALBASE}/bin/qt2kdoc \
		--outdir=${WRKDIR}/kdelibs \
		${QT2DIR}/qt2/doc/html
	${LOCALBASE}/bin/makekdedoc \
		--srcdir=${WRKSRC} \
		--outputdir=${WRKDIR}/kdelibs \
		--libdir=${WRKDIR}/kdelibs

do-install:
	cd ${WRKDIR}; \
	DOCDIRS="`${FIND} kdelibs -type d -print | ${SORT}`"; \
	for d in $${DOCDIRS}; do \
	    ${ECHO} creating directory ${DOCINSTALLDIR}/$${d}; \
	    ${INSTALL_DATA_DIR} ${DOCINSTALLDIR}/$${d}; \
	done ; \
	DOCFILES="`${FIND} kdelibs -type f -print | ${SORT}`"; \
	(for f in $${DOCFILES}; do \
	    ${ECHO} installing ${DOCINSTALLDIR}/$${f}; \
	    ${INSTALL_DATA} $${f} ${DOCINSTALLDIR}/$${f}; \
	done)

.include "../../mk/bsd.pkg.mk"
