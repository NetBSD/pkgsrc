# $NetBSD: Makefile,v 1.6 2001/01/11 17:55:56 skrll Exp $
#

PKGNAME=	qt2-docs-${QTVERSION}

.include "../qt2-libs/Makefile.common"

DEPENDS+=	qt2-libs-${QTVERSION}:../../x11/qt2-libs

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
	cd ${WRKSRC}/doc/html;  \
	DOCDIRS="`find . -type d -print | sort`"; \
	(for d in $${DOCDIRS}; do \
	    ${ECHO} installing ${QTPREFIX}/doc/html/$${d}; \
	    ${INSTALL_DATA_DIR} ${QTPREFIX}/doc/html/$${d}; \
	done) ; \
	DOCFILES="`find . -type f -print | sort`"; \
	(for f in $${DOCFILES}; do \
	    ${ECHO} installing ${QTPREFIX}/doc/html/$${f}; \
	    ${INSTALL_DATA} $${f} ${QTPREFIX}/doc/html/$${f}; \
	done)

.include "../../mk/bsd.pkg.mk"
