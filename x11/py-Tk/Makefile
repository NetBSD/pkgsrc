# $NetBSD: Makefile,v 1.11 1999/04/26 19:30:27 garbled Exp $
#

DISTNAME=	py152
PKGNAME=	py-Tk-1.5.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.python.org/pub/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/topics/tkinter/

DEPENDS+=	python-1.5.2:../../lang/python
DEPENDS+=	tk-8.0.5:../../x11/tk80
DEPENDS+=	tcl-8.0.5:../../lang/tcl80

DIST_SUBDIR=	python

USE_X11=	yes
WRKSRC=		${WRKDIR}/Python-1.5.2/Modules
ALL_TARGET=	default
EXTRACT_ELEMENTS=	Python-1.5.2/Modules/_tkinter.c \
			Python-1.5.2/Modules/tkappinit.c

PYTHON_CONFIGDIR=	${LOCALBASE}/lib/python1.5/config/

.if ${MACHINE_ARCH} == "sparc64"
IGNORE="Needs dynamic loading"
.endif

do-configure:
	${SED} -e 's%@LOCALBASE@%${LOCALBASE}%g' \
	 -e 's%@X11BASE@%${X11BASE}%g' ${FILESDIR}/Setup.in \
	 >${WRKSRC}/Setup.in
	( cd ${WRKSRC} ;\
	  ${LN} -s ${PYTHON_CONFIGDIR}/Makefile.pre.in ;\
	  ${MAKE} -f Makefile.pre.in boot)

do-install:
	${INSTALL_DATA} ${WRKSRC}/_tkinter.so ${LOCALBASE}/lib/python1.5/lib-dynload

.include "../../mk/bsd.pkg.mk"
