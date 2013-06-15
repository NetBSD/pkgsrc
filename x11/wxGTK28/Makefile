# $NetBSD: Makefile,v 1.34 2013/06/15 06:57:55 ryoon Exp $
#

.include "../../x11/wxGTK28/Makefile.common"

PKGNAME=		${DISTNAME:S/wxGTK/wxGTK28/}
PKGREVISION=		1
COMMENT=		GTK-based implementation of the wxWidgets GUI library

BUILD_TARGET=	all
INSTALL_TARGET=	install

INSTALLATION_DIRS=	${DOCDIR}

REPLACE_SH=		wx-config.in wx-config-inplace.in

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

.include "../../mk/bsd.prefs.mk"

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
