# $NetBSD: Makefile,v 1.7 2003/12/13 00:45:25 wiz Exp $
#

DISTNAME=		gDeskCal-0_55
PKGNAME=		gdeskcal-0.55
PKGREVISION=		1
CATEGORIES=		time
MASTER_SITES=		http://www.pycage.de/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.pycage.de/software_gdeskcal.html
COMMENT=		Desktop calendar

WRKSRC=		${WRKDIR}/gDeskCal-0.55
USE_BUILDLINK2=	yes
NO_BUILD=	yes

PYTHON_VERSIONS_ACCEPTED=	22pth 23pth
PYTHON_PATCH_SCRIPTS=	gdeskcal

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gdeskcal
	(cd ${WRKSRC} && ${CP} -r . ${PREFIX}/lib/gdeskcal)
	${PYTHONBIN} ${LOCALBASE}/${PYLIB}/compileall.py \
		${PREFIX}/lib/gdeskcal/code
	${LN} -s ${PREFIX}/lib/gdeskcal/gdeskcal ${PREFIX}/bin

.include "../../x11/py-gtk2/buildlink2.mk"
.include "../../textproc/pyxml/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
