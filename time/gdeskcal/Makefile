# $NetBSD: Makefile,v 1.14 2004/10/03 00:18:22 tv Exp $
#

DISTNAME=		gDeskCal-0_57
PKGNAME=		gdeskcal-0.57
PKGREVISION=		2
CATEGORIES=		time
MASTER_SITES=		http://www.pycage.de/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.pycage.de/software_gdeskcal.html
COMMENT=		Desktop calendar

WRKSRC=		${WRKDIR}/gDeskCal-0.57
USE_BUILDLINK3=	yes
NO_BUILD=	yes

PYTHON_VERSIONS_ACCEPTED=	22pth 23pth
PYTHON_PATCH_SCRIPTS=	gdeskcal

post-extract:
	${RM} ${WRKSRC}/data/format.xml~

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gdeskcal
	(cd ${WRKSRC} && ${CP} -r . ${PREFIX}/lib/gdeskcal)
	${PYTHONBIN} ${LOCALBASE}/${PYLIB}/compileall.py \
		${PREFIX}/lib/gdeskcal/code
	${LN} -s ${PREFIX}/lib/gdeskcal/gdeskcal ${PREFIX}/bin

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
