# $NetBSD: Makefile,v 1.5 2003/07/26 15:25:28 drochner Exp $
#

DISTNAME=		gDeskCal-0_54
PKGNAME=		gdeskcal-0.54
CATEGORIES=		time
MASTER_SITES=		http://www.pycage.de/download/

MAINTAINER=		packages@NetBSD.org
HOMEPAGE=		http://www.pycage.de/software_gdeskcal.html
COMMENT=		Desktop calendar

WRKSRC=		${WRKDIR}/gDeskCal-0.54
USE_BUILDLINK2=		yes
NO_BUILD=	yes

PYTHON_VERSION_REQD=	22pth
PYTHON_PATCH_SCRIPTS=	gdeskcal

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gdeskcal
	(cd ${WRKSRC} && ${CP} -r . ${PREFIX}/lib/gdeskcal)
	${RM} -f ${PREFIX}/lib/gdeskcal/po/de.po~
	${PYTHONBIN} ${LOCALBASE}/${PYLIB}/compileall.py \
		${PREFIX}/lib/gdeskcal/code
	${LN} -s ${PREFIX}/lib/gdeskcal/gdeskcal ${PREFIX}/bin

.include "../../x11/py-gtk2/buildlink2.mk"
.include "../../textproc/pyxml/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
