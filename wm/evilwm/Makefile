# $NetBSD: Makefile,v 1.11 2004/03/10 14:12:51 xtraeme Exp $
#

DISTNAME=	evilwm_0.99.17.orig
PKGNAME=	${DISTNAME:S/.orig//:S/_/-/}
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=evilwm/}

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://evilwm.sourceforge.net/
COMMENT=	Minimalist Window Manager for X

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_BUILDLINK3=	yes
USE_X11=	yes

ALL_TARGET=	allinone

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/evilwm
	cd ${WRKSRC} && \
	${INSTALL_DATA} ChangeLog README README.vdesk TODO	\
		${PREFIX}/share/doc/evilwm

.include "../../mk/bsd.pkg.mk"
