# $NetBSD: Makefile,v 1.10 2001/11/16 08:43:33 jlam Exp $
#

PKGNAME=	qt2-docs-${QTVERSION}
COMMENT=	Documentation for the QT C++ X GUI toolkit

.include "../qt2-libs/Makefile.common"

USE_BUILDLINK_ONLY=		yes
BUILDLINK_DEPENDS.qt2-libs=	qt2-libs-${QTVERSION}

NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}/doc
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.QT ${QTPREFIX}/doc
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
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.QT ${QTPREFIX}/doc/html
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

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
