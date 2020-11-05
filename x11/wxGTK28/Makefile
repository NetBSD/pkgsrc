# $NetBSD: Makefile,v 1.59 2020/11/05 09:09:29 ryoon Exp $
#

.include "../../x11/wxGTK28/Makefile.common"

PKGNAME=		${DISTNAME:S/wxGTK/wxGTK28/}
PKGREVISION=		23
COMMENT=		GTK-based implementation of the wxWidgets GUI library

BUILD_TARGET=	all
INSTALL_TARGET=	install

INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	bin

REPLACE_SH=		wx-config.in wx-config-inplace.in

# We patch configure
CHECK_PORTABILITY_SKIP+=	configure.in

post-configure:
	echo 'install_qadll: install_xmldll' >> ${WRKSRC}/build-unicode/Makefile
	echo 'install_qadll: install_xmldll' >> ${WRKSRC}/build-non-unicode/Makefile

post-build:
	set -e; cd ${WRKSRC}/locale; \
	for lang in *.po; do \
		[ "$${lang}" = "wxstd.po" ] && continue; \
		${TOOLS_PATH.msgfmt} -c -o "$${lang%.po}.mo" "$${lang}"; \
	done
	set -e; cd ${WRKSRC}/locale/msw; \
	for lang in it; do \
	    ${TOOLS_PATH.msgfmt} -c -o "$${lang}.mo" "$${lang}.po"; \
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/licence.txt ${DESTDIR}${DOCDIR}
	# Create symlinks for now.  Eventually we may want to use ALTERNATIVES
	${LN} -sf ../libexec/wx-2.8/wxrc ${DESTDIR}${PREFIX}/bin/wxrc
	${LN} -sf ../libexec/wx-2.8/wxrc-2.8 ${DESTDIR}${PREFIX}/bin/wxrc-2.8
	${LN} -sf ../libexec/wx-2.8/wx-config ${DESTDIR}${PREFIX}/bin/wx-config
	${LN} -sf ../libexec/wx-2.8/wx-config ${DESTDIR}${PREFIX}/bin/wx-config-2.8

.include "../../mk/bsd.prefs.mk"

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
