# $NetBSD: Makefile,v 1.8 2003/12/11 19:24:33 ben Exp $
#

DISTNAME=		RTF-1.10
PKGNAME=		rtf-tools-1.10
PKGREVISION=		1
WRKSRC=			${WRKDIR}/rtf
CATEGORIES=		textproc
MASTER_SITES=		http://www.snake.net/software/RTF/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		${MASTER_SITES}
COMMENT=		RTF to troff/groff/text converter

BUILD_DEPENDS+=		libts-1.08:../../devel/libts

INSTALL_TARGET=		install install.man

post-patch:
	for i in `${FIND} ${WRKSRC} -name Makefile`; do \
		${MV} $$i $$i.bak;\
		${SED} <$$i.bak >$$i \
			-e "s|/usr/local|${PREFIX}|g" \
			-e "s|/usr/man|${PREFIX}/man|" \
			-e "s|\(LOCALBINDIR =.*\)|\1/bin|" ;\
	done

.include "../../mk/bsd.pkg.mk"
