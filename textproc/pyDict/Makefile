# $NetBSD: Makefile,v 1.13 2004/10/03 00:18:21 tv Exp $

DISTNAME=	pyDict-0.2.5.1
PKGREVISION=	4
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pydict/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pydict/
COMMENT=	Chinese <-> English dictionary, under both console and X11

WRKSRC=		${WRKDIR}/dict
USE_X11BASE=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_BUILDLINK3=	yes

PYTHON_PATCH_SCRIPTS=	dict.py

post-patch:
	${SED} -e 's:/bin/grep:'${GREP}':g' < ${WRKSRC}/dict.py > ${WRKSRC}/dict.py.tmp
	${SED} -e 's:/usr/X11R6:'${PREFIX}':g' < ${WRKSRC}/dict.py.tmp > ${WRKSRC}/dict.py

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/pyDict
	${INSTALL_DATA} ${WRKSRC}/[a-z].lib ${WRKSRC}/dict.xpm ${WRKSRC}/yaba.xpm ${WRKSRC}/HELP ${PREFIX}/lib/X11/pyDict
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pyDict
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/COPYING ${WRKSRC}/README ${PREFIX}/share/doc/pyDict
	${INSTALL_SCRIPT} ${WRKSRC}/dict.py ${PREFIX}/bin/pydict

.include "../../lang/python/application.mk"
.include "../../x11/pygtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
