# $NetBSD: Makefile,v 1.3 2003/01/19 06:07:19 salo Exp $
#

DISTNAME=	evilwm_0.99.14.orig
PKGNAME=	evilwm-0.99.14
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=evilwm/}

MAINTAINER=	sketch@rd.bbc.co.uk
HOMEPAGE=	http://evilwm.sourceforge.net/
COMMENT=	Minimalist Window Manager for X

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

USE_GMAKE=	YES
USE_X11BASE=	YES

ALL_TARGET=	allinone

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/evilwm
	cd ${WRKSRC} && \
	${INSTALL_DATA} ChangeLog README README.vdesk TODO	\
		${PREFIX}/share/doc/evilwm

.include "../../mk/bsd.pkg.mk"
