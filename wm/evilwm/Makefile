# $NetBSD: Makefile,v 1.12 2004/12/03 15:15:11 wiz Exp $
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

BUILD_TARGET=	allinone

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/evilwm
	cd ${WRKSRC} && \
	${INSTALL_DATA} ChangeLog README README.vdesk TODO	\
		${PREFIX}/share/doc/evilwm

.include "../../mk/bsd.pkg.mk"
