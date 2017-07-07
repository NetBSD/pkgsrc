# $NetBSD: Makefile,v 1.36 2017/07/07 13:08:07 jperkin Exp $
#

DISTNAME=	evilwm-1.1.1
CATEGORIES=	wm x11
MASTER_SITES=	http://www.6809.org.uk/evilwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.6809.org.uk/evilwm/
COMMENT=	Minimalist Window Manager for X

USE_TOOLS+=	gmake
MAKE_FLAGS+=	OPT_CPPFLAGS=-D_XOPEN_SOURCE=600

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/evilwm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/evilwm ${DESTDIR}${PREFIX}/bin/evilwm
	${INSTALL_MAN} ${WRKSRC}/evilwm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/evilwm.1
	for docfile in ChangeLog README TODO; \
	do \
	    ${INSTALL_DATA} ${WRKSRC}/$$docfile ${DESTDIR}${PREFIX}/share/doc/evilwm/; \
	done

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
