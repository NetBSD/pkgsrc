# $NetBSD: Makefile,v 1.41 2016/03/05 11:29:47 jperkin Exp $

.include "../../x11/qt3-libs/Makefile.common"

PKGNAME=	qt3-docs-${QTVERSION}
PKGREVISION=	15
COMMENT=	Documentation for the QT C++ X GUI toolkit

BUILD_QT3=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	${QTPREFIX}/doc/html ${QTPREFIX}/man/man3

do-install:
	set -e; \
	cd ${WRKSRC}/doc/man/man3; PAGES="`ls -1 | ${SED} -e 's,3qt$$,3,'`"; \
	(for PAGE in $$PAGES; do \
	    ${ECHO} installing ${DESTDIR}${QTPREFIX}/man/man3/$${PAGE}; \
	    set - X `head -1 $${PAGE}qt`; \
	    if [ $$# -eq 3 ] && [ "$$2" = .so ]; then \
		${LN} -fs `basename $$3 | ${SED} 's/qt$$//'` \
		  ${DESTDIR}${QTPREFIX}/man/man3/$${PAGE}; \
	    else \
		${INSTALL_MAN} $${PAGE}qt ${DESTDIR}${QTPREFIX}/man/man3/$${PAGE}; \
	    fi; \
	 done)
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README-QT.TXT ${DESTDIR}${QTPREFIX}/doc/html
	set -e; \
	cd ${WRKSRC};  \
	DOCDIRS="`${FIND} doc/html -type d -print | ${SORT}`"; \
	(for d in $${DOCDIRS}; do \
	    ${ECHO} installing ${DESTDIR}${QTPREFIX}/$${d}; \
	    ${INSTALL_DATA_DIR} ${DESTDIR}${QTPREFIX}/$${d}; \
	done) ; \
	DOCFILES="`${FIND} doc/html -type f -print | ${SORT}`"; \
	(for f in $${DOCFILES}; do \
	    ${ECHO} installing ${DESTDIR}${QTPREFIX}/$${f}; \
	    ${INSTALL_DATA} $${f} ${DESTDIR}${QTPREFIX}/$${f}; \
	done)

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
