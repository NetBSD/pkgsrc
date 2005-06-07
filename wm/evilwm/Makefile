# $NetBSD: Makefile,v 1.15 2005/06/07 15:01:09 sketch Exp $
#

DISTNAME=	evilwm-0.99.18
CATEGORIES=	wm x11
MASTER_SITES=	http://www.6809.org.uk/evilwm/

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://www.6809.org.uk/evilwm/
COMMENT=	Minimalist Window Manager for X

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/evilwm ${PREFIX}/bin/evilwm
	${INSTALL_MAN} ${WRKSRC}/evilwm.1 ${PREFIX}/man/man1/evilwm.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/evilwm
	for file in ChangeLog README TODO; \
	do \
	    ${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/evilwm/; \
	done
	

.include "../../mk/bsd.pkg.mk"
