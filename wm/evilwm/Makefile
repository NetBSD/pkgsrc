# $NetBSD: Makefile,v 1.2 2002/03/04 15:56:37 agc Exp $
#

DISTNAME=	evilwm_0.99.4-1
PKGNAME=	evilwm-0.99.4
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=evilwm/}

MAINTAINER=	sketch@rd.bbc.co.uk
HOMEPAGE=	http://evilwm.sourceforge.net/
COMMENT=	Minimalist Window Manager for X

WRKSRC=		${WRKDIR}/${PKGNAME}

USE_GMAKE=		YES
USE_X11BASE=		YES

ALL_TARGET=		allinone

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/evilwm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/evilwm
	${INSTALL_DATA} ${WRKSRC}/README.multihead ${PREFIX}/share/doc/evilwm
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/evilwm

.include "../../mk/bsd.pkg.mk"
