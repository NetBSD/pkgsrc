# $NetBSD: Makefile,v 1.4 2001/11/29 01:12:50 hubertf Exp $
#

DISTNAME=		RTF-1.10
PKGNAME=		rtf-tools-1.10
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		http://www.primate.wisc.edu/software/RTF/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.primate.wisc.edu/software/RTF/
COMMENT=		RTF to troff/groff/text converter

BUILD_DEPENDS+=		libts-1.08:../../devel/libts

WRKSRC=			${WRKDIR}/rtf
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
