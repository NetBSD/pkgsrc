# $NetBSD: Makefile,v 1.27 2008/01/10 23:08:22 dan Exp $
#

DISTNAME=	evilwm-1.0.0
CATEGORIES=	wm x11
MASTER_SITES=	http://www.6809.org.uk/evilwm/

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://www.6809.org.uk/evilwm/
COMMENT=	Minimalist Window Manager for X

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/evilwm ${PREFIX}/bin/evilwm
	${INSTALL_MAN} ${WRKSRC}/evilwm.1 ${PREFIX}/${PKGMANDIR}/man1/evilwm.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/evilwm
	for docfile in ChangeLog README TODO; \
	do \
	    ${INSTALL_DATA} ${WRKSRC}/$$docfile ${PREFIX}/share/doc/evilwm/; \
	done

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
