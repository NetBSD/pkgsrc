# $NetBSD: Makefile,v 1.2 1999/09/29 22:58:46 tron Exp $

DISTNAME=		glclock-4.6
CATEGORIES=		x11 graphics
MASTER_SITES=		http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.daionet.gr.jp/~masa/glclock

DEPENDS=		Mesa-*:../../graphics/Mesa

USE_X11BASE=		yes
MAKEFILE=		makefile
ALL_TARGET=		glclock

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glclock ${PREFIX}/bin
#notyet: lookup of .ppm files
#	for i in benchclock crystalclock marbleclock metalclock \
#			mwclock woodclock;do \
#	${INSTALL_SCRIPT} ${WRKSRC}/$$i ${PREFIX}/bin; done

.include "../../mk/bsd.pkg.mk"
