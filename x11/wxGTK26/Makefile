# $NetBSD: Makefile,v 1.1.1.1 2008/09/22 19:44:05 joerg Exp $
#

.include "Makefile.common"

PKGREVISION=		2
COMMENT=		GTK-based implementation of the wxWidgets GUI library

post-build:
	set -e; cd ${WRKSRC}/locale; \
	for lang in ca cs da de el es fi fr hu id it ja nl pl ru sl sv tr uk \
	    zh_CN zh_TW; do \
		${TOOLS_PATH.msgfmt} -c -o $${lang}.mo $${lang}.po; \
	done
	set -e; cd ${WRKSRC}/locale/msw; \
	for lang in it; do \
	    ${TOOLS_PATH.msgfmt} -c -o $${lang}.mo $${lang}.po; \
	done

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DESTDIR}${DOCDIR}/LICENSE

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
