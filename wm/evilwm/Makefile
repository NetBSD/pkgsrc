# $NetBSD: Makefile,v 1.1.1.1 2001/12/21 23:14:36 zuntum Exp $
#

DISTNAME=	evilwm_0.3.11-1
PKGNAME=	evilwm-0.3.11
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=evilwm/}

MAINTAINER=	sketch@rd.bbc.co.uk
HOMEPAGE=	http://evilwm.sourceforge.net/
COMMENT=	Minimalist Window Manager for X

WRKSRC=		${WRKDIR}/evilwm-0.3.11

USE_GMAKE=		YES
USE_X11BASE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/evilwm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/evilwm
	${INSTALL_DATA} ${WRKSRC}/README.multihead ${PREFIX}/share/doc/evilwm
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/evilwm

.include "../../mk/bsd.pkg.mk"
