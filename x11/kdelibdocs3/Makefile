# $NetBSD: Makefile,v 1.1.1.1 2002/07/17 11:12:52 skrll Exp $

DISTNAME=	kdelibs-3.0.2
PKGNAME=	${DISTNAME:S/kdelib/kdelibdoc/}
CATEGORIES=	x11 devel

COMMENT=	KDE library documentation

.include "../../x11/kde3/Makefile.kde3"

BUILD_DEPENDS+=		kdoc>=3.0:../../textproc/kdoc
DEPENDS+=		qt3-docs>=3.0.4:../../x11/qt3-docs

USE_X11BASE=		yes
NO_CONFIGURE=		yes

EVAL_PREFIX+=		QT3DIR=qt3
DOCINSTALLDIR=		${X11PREFIX}/share/doc/kde/HTML/en

do-build:
	${MKDIR} ${WRKDIR}/kdelibs
	${SETENV} PATH=${LOCALBASE}/bin:${PATH} ${LOCALBASE}/bin/qt2kdoc \
		--outdir=${WRKDIR}/kdelibs/kdoc-reference		\
		${QT3DIR}/qt3/doc/html
	${SETENV} PATH=${LOCALBASE}/bin:${PATH} ${LOCALBASE}/bin/makekdedoc \
		--srcdir=${WRKSRC}					\
		--outputdir=${WRKDIR}/kdelibs				\
		--libdir=${WRKDIR}/kdelibs/kdoc-reference

do-install:
	cd ${WRKDIR};							\
	DOCDIRS="`${FIND} kdelibs -type d -print | ${SORT}`";		\
	for d in $${DOCDIRS}; do					\
	    ${ECHO} creating directory ${DOCINSTALLDIR}/$${d};		\
	    ${INSTALL_DATA_DIR} ${DOCINSTALLDIR}/$${d};			\
	done ;								\
	DOCFILES="`${FIND} kdelibs -type f -print | ${SORT}`";		\
	(for f in $${DOCFILES}; do					\
	    ${ECHO} installing ${DOCINSTALLDIR}/$${f};			\
	    ${INSTALL_DATA} $${f} ${DOCINSTALLDIR}/$${f};		\
	done)

.include "../../mk/bsd.pkg.mk"
