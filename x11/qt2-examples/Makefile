# $NetBSD: Makefile,v 1.6 2001/11/16 09:09:34 jlam Exp $
#

PKGNAME=	qt2-examples-${QTVERSION}
COMMENT=	QT2 Tutorial, example code and HTML documentation

.include "../qt2-libs/Makefile.common"

USE_BUILDLINK_ONLY=		yes
BUILDLINK_DEPENDS.qt2-libs=	qt2-libs>=${QTVERSION}

CONFIGURE_ENV+=	QTDIR=${QTPREFIX}

do-build:
	@MFS="`${FIND} ${WRKSRC}/examples ${WRKSRC}/tutorial -name Makefile -print`"; \
	(for M in $${MFS}; do \
	    ${SED} \
		-e "s:\\\$$[({]X11BASE[})]:${X11BASE}:g" \
		-e "s:\\\$$[({]QTDIR[})]:${QTPREFIX}:g" \
		-e "s:\\\$$[({]LOCALBASE[})]:${LOCALBASE}:g" \
		-e "s:\\\$$[({]LIBTOOL[})]:${LIBTOOL}:g" \
		$${M} > $${M}.new; \
	    ${MV} $${M}.new $${M}; \
	done)

do-install:
	@cd ${WRKSRC}; \
	DIRS="`${FIND} examples tutorial -type d -print | ${SORT}`"; \
	(for d in $${DIRS}; do \
	    ${ECHO} creating ${QTPREFIX}/$${d}; \
	    ${INSTALL_DATA_DIR} ${QTPREFIX}/$${d}; \
	done); \
	ETFILES="`${FIND} examples tutorial -type f ! -name "Makefile.in" -print | ${SORT}`"; \
	(for f in $${ETFILES}; do \
	    ${ECHO} installing ${QTPREFIX}/$${f}; \
	    ${INSTALL_DATA} $${f} ${QTPREFIX}/$${f}; \
	done)

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
