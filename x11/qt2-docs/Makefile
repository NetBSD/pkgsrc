# $NetBSD: Makefile,v 1.3 2000/11/03 08:37:05 skrll Exp $
#

PKGNAME=	qt2-docs-2.2.1

.include "../qt2-libs/Makefile.common"

DEPENDS+=	qt2-libs-*:../../x11/qt2-libs

NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}/doc
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.QT ${QTPREFIX}/doc
	${INSTALL_DATA_DIR} ${QTPREFIX}/doc/man
	${INSTALL_MAN_DIR}  ${QTPREFIX}/doc/man/man3
	@cd ${WRKSRC}/doc/man/man3; PAGES="`ls -1 | ${SED} -e 's,3qt$$,3,'`"; \
	(for PAGE in $$PAGES; do \
	    ${ECHO} installing ${QTPREFIX}/doc/man/man3/$${PAGE}; \
	    set - X `head -1 $${PAGE}qt`; \
	    if [ $$# -eq 3 ] && [ "$$2" = .so ]; then \
		${LN} -fs `basename $$3 | ${SED} s/qt$$//` \
		  ${QTPREFIX}/doc/man/man3/$${PAGE}; \
	    else \
		${INSTALL_MAN} $${PAGE}qt ${QTPREFIX}/doc/man/man3/$${PAGE}; \
	    fi; \
	 done)

.include "../../mk/bsd.pkg.mk"
