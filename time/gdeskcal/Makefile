# $NetBSD: Makefile,v 1.56 2014/05/09 07:37:22 wiz Exp $

DISTNAME=	gDeskCal-0_57_1
PKGNAME=	gdeskcal-0.57.1
PKGREVISION=	27
CATEGORIES=	time
MASTER_SITES=	http://www.pycage.de/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pycage.de/\#gdeskcal
COMMENT=	Desktop calendar

WRKSRC=		${WRKDIR}/gDeskCal-0.57.1
NO_BUILD=	yes

REPLACE_PYTHON=	gdeskcal

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-xml, py-gtk2

INSTALLATION_DIRS=	bin lib/gdeskcal

post-extract:
	${RM} ${WRKSRC}/data/format.xml~

do-install:
	(cd ${WRKSRC} && ${CP} -r . ${DESTDIR}${PREFIX}/lib/gdeskcal)
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/lib/gdeskcal/code
	${LN} -s ../lib/gdeskcal/gdeskcal ${DESTDIR}${PREFIX}/bin

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
