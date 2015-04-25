# $NetBSD: Makefile,v 1.33 2015/04/25 14:25:20 tnn Exp $
#

.include "Makefile.common"

PKGREVISION=		30
COMMENT=		GTK-based implementation of the wxWidgets GUI library

REPLACE_SH=		wx-config.in wx-config-inplace.in

post-configure:
	echo 'install_qadll: install_xmldll' >> ${WRKSRC}/Makefile

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

# for backtrace
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
