# $NetBSD: Makefile,v 1.4 2026/05/17 09:07:55 wiz Exp $

.include "../../x11/libxkbcommon/Makefile.common"

PKGNAME=		${DISTNAME:S/common/common-docs/:S/^/lib/}
PKGREVISION=		1

TOOL_DEPENDS+=		doxygen>=1.17:../../devel/doxygen
MESON_ARGS+=		-Denable-docs=true

# conflicts with removed doc option
CONFLICTS+=		libxkbcommon<1.13.1nb2

# TODO: find way to avoid building these parts
post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/bin
	${RM} -rf ${DESTDIR}${PREFIX}/include
	${RM} -rf ${DESTDIR}${PREFIX}/lib
	${RM} -rf ${DESTDIR}${PREFIX}/libexec
	${RM} -rf ${DESTDIR}${PREFIX}/${PKGMANDIR}
	${RM} -rf ${DESTDIR}${PREFIX}/share/bash-completion

.include "../../mk/bsd.pkg.mk"
