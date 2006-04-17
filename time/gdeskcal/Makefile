# $NetBSD: Makefile,v 1.24 2006/04/17 13:46:49 wiz Exp $
#

DISTNAME=		gDeskCal-0_57_1
PKGNAME=		gdeskcal-0.57.1
PKGREVISION=		3
CATEGORIES=		time
MASTER_SITES=		http://www.pycage.de/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pycage.de/software_gdeskcal.html
COMMENT=		Desktop calendar

WRKSRC=		${WRKDIR}/gDeskCal-0.57.1
NO_BUILD=	yes

PYTHON_VERSIONS_ACCEPTED=	24 23
PYTHON_PATCH_SCRIPTS=	gdeskcal
INSTALLATION_DIRS=	bin

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
