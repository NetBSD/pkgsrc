# $NetBSD: Makefile,v 1.15 2004/10/03 00:18:38 tv Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=	qt3-docs-${QTVERSION}
PKGREVISION=	1
COMMENT=	Documentation for the QT C++ X GUI toolkit

USE_BUILDLINK3=	yes
BUILD_QT3=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}/doc
	${INSTALL_DATA_DIR} ${QTPREFIX}/man
	${INSTALL_MAN_DIR}  ${QTPREFIX}/man/man3
	@cd ${WRKSRC}/doc/man/man3; PAGES="`ls -1 | ${SED} -e 's,3qt$$,3,'`"; \
	(for PAGE in $$PAGES; do \
	    ${ECHO} installing ${QTPREFIX}/man/man3/$${PAGE}; \
	    set - X `head -1 $${PAGE}qt`; \
	    if [ $$# -eq 3 ] && [ "$$2" = .so ]; then \
		${LN} -fs `basename $$3 | ${SED} s/qt$$//` \
		  ${QTPREFIX}/man/man3/$${PAGE}; \
	    else \
		${INSTALL_MAN} $${PAGE}qt ${QTPREFIX}/man/man3/$${PAGE}; \
	    fi; \
	 done)
	${INSTALL_DATA_DIR} ${QTPREFIX}/doc/html
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README-QT.TXT ${QTPREFIX}/doc/html
	cd ${WRKSRC};  \
	DOCDIRS="`${FIND} doc/html -type d -print | ${SORT}`"; \
	(for d in $${DOCDIRS}; do \
	    ${ECHO} installing ${QTPREFIX}/$${d}; \
	    ${INSTALL_DATA_DIR} ${QTPREFIX}/$${d}; \
	done) ; \
	DOCFILES="`${FIND} doc/html -type f -print | ${SORT}`"; \
	(for f in $${DOCFILES}; do \
	    ${ECHO} installing ${QTPREFIX}/$${f}; \
	    ${INSTALL_DATA} $${f} ${QTPREFIX}/$${f}; \
	done)

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
