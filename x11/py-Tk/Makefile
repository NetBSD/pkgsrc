# $NetBSD: Makefile,v 1.15 2000/10/22 20:01:51 tsarna Exp $
#

DISTNAME=	${PY_DISTNAME}
PKGNAME=	py-Tk-${PY_VERSION}
CATEGORIES=	x11
MASTER_SITES=	${PY_MASTER_SITES}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/topics/tkinter/

DEPENDS+=	tk-*:../../x11/tk
DEPENDS+=	tcl-*:../../lang/tcl

USE_X11=	yes
WRKSRC=		${PY_WRKSRC}

EXTRACT_ELEMENTS=	${PY_MODULES}/_tkinter.c \
			${PY_MODULES}/tkappinit.c

do-configure:	python-std-do-configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/_tkinter.so ${PY_LIBDIR}/lib-dynload
	${INSTALL_DATA} ${WRKSRC}/Setup.in ${PY_CONFIGDIR}/Setup.tk

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
