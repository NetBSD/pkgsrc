# $NetBSD: Makefile,v 1.14 2005/06/01 18:03:25 jlam Exp $
#

DISTNAME=	evilwm_0.99.17.orig
PKGNAME=	${DISTNAME:S/.orig//:S/_/-/}
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=evilwm/}

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://evilwm.sourceforge.net/
COMMENT=	Minimalist Window Manager for X

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

BUILD_TARGET=	allinone

.include "../../mk/x11.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/evilwm
	cd ${WRKSRC} && \
	${INSTALL_DATA} ChangeLog README README.vdesk TODO	\
		${PREFIX}/share/doc/evilwm

.include "../../mk/bsd.pkg.mk"
