# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 12:27:06 agc Exp $
#

DISTNAME=		troffcvt-1.04
CATEGORIES=		textproc
MASTER_SITES=		http://www.primate.wisc.edu/software/troffcvt/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.primate.wisc.edu/software/troffcvt/
COMMENT=		Troff/groff to RTF/HTML/TEXT converter

BUILD_DEPENDS+=		libts-1.08:../../devel/libts
BUILD_DEPENDS+=		libmemmgr-1.04:../../devel/libmemmgr
BUILD_DEPENDS+=		libportlib-1.01:../../devel/libportlib

#WRKSRC=			${WRKDIR}/rtf
INSTALL_TARGET=		install install.man

post-patch:
	for i in `${FIND} ${WRKSRC} -name Makefile`; do \
		${MV} $$i $$i.bak;\
		${SED} <$$i.bak >$$i \
			-e "s| -Dsun -DSVR4||" \
			-e "s| -lsocket -lnsl -lw||" \
			-e "s| -Xc||" \
			-e "s|/usr/include/sys/feature_tests.h||" \
			-e "s|/usr/tmp|/tmp|g" \
			-e "s|/usr/ucb/install|${INSTALL}|" \
			-e "s|/usr/local|${PREFIX}|g" \
			-e "s|/usr/local/man|${PREFIX}/man|" ;\
	done

.include "../../mk/bsd.pkg.mk"
