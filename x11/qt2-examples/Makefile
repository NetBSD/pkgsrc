# $NetBSD: Makefile,v 1.2 2001/02/06 09:26:15 skrll Exp $
#

PKGNAME=	qt2-examples-${QTVERSION}

.include "../qt2-libs/Makefile.common"

DEPENDS+=	qt2-libs-${QTVERSION}:../../x11/qt2-libs

CONFIGURE_ENV+=	QTDIR=${QTPREFIX}

do-build:
	@MFS="`find ${WRKSRC}/examples ${WRKSRC}/tutorial -name Makefile -print`"; \
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
	DIRS="`find examples tutorial -type d -print | sort`"; \
	(for d in $${DIRS}; do \
	    ${ECHO} creating ${QTPREFIX}/$${d}; \
	    ${INSTALL_DATA_DIR} ${QTPREFIX}/$${d}; \
	done); \
	ETFILES="`find  examples tutorial -type f ! -name "Makefile.in" -print | sort`"; \
	(for f in $${ETFILES}; do \
	    ${ECHO} installing ${QTPREFIX}/$${f}; \
	    ${INSTALL_DATA} $${f} ${QTPREFIX}/$${f}; \
	done)

.include "../../mk/bsd.pkg.mk"
