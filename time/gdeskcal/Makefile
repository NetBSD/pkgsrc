# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 19:33:15 drochner Exp $
#

DISTNAME=		gDeskCal-0_51
PKGNAME=		gdeskcal-0.51
CATEGORIES=		time
MASTER_SITES=		http://www.pycage.de/download/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.pycage.de/software_gdeskcal.html
COMMENT=		desktop calendar

WRKSRC=		${WRKDIR}/gDeskCal-0.51
USE_BUILDLINK2=		yes
NO_BUILD=	yes

PYTHON_VERSION_REQD=	22pth
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
