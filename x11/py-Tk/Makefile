# $NetBSD: Makefile,v 1.4 1998/09/06 22:01:09 frueauf Exp $
#

DISTNAME=	pyth151
PKGNAME=	py-Tk-1.5.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.python.org/pub/python/src/
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	python

MAINTAINER=	dolecek@ics.muni.cz
HOMEPAGE=	http://www.python.org/topics/tkinter/

DEPENDS+=	python-1.5.1:../../lang/python
DEPENDS+=	tk-8.0p2:../../x11/tk80
DEPENDS+=	tcl-8.0p2:../../lang/tcl80

WRKSRC=		${WRKDIR}/Python-1.5.1/Modules
ALL_TARGET=	default
EXTRACT_AFTER_ARGS=	Python-1.5.1/Modules/_tkinter.c \
			Python-1.5.1/Modules/tkappinit.c

PYTHON_CONFIGDIR=	${LOCALBASE}/lib/python1.5/config/

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "alpha"
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
