# $NetBSD: Makefile,v 1.7 2003/09/16 19:23:34 xtraeme Exp $
#

DISTNAME=	evilwm_0.99.15.orig
PKGNAME=	${DISTNAME:S/.orig//:S/_/-/}
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=evilwm/}

MAINTAINER=	jonathan@perkin.org.uk
HOMEPAGE=	http://evilwm.sourceforge.net/
COMMENT=	Minimalist Window Manager for X

USE_GMAKE=	YES
USE_X11=	YES

ALL_TARGET=	allinone

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/evilwm
	cd ${WRKSRC} && \
	${INSTALL_DATA} ChangeLog README README.vdesk TODO	\
		${PREFIX}/share/doc/evilwm

.include "../../mk/bsd.pkg.mk"
