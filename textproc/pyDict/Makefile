# $NetBSD: Makefile,v 1.4 2002/10/29 17:51:11 drochner Exp $

DISTNAME=	pyDict-0.2.5.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pydict/}

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/pydict/
COMMENT=	Chinese <-> English dictionary, under both console and X11

USE_X11BASE=	yes

WRKSRC=		${WRKDIR}/dict
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_BUILDLINK2=	yes

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
.include "../../x11/pygtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
