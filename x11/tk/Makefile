# $NetBSD: Makefile,v 1.17 2001/12/23 17:11:30 bjoern Exp $

DISTNAME=	tk8.3.4
PKGNAME=	tk-8.3.4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_3/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/soft/lang/tcl/tcl8_3/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.tcltk.com/
COMMENT=	Graphical toolkit for TCL

WRKSRC=			${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_DIR}/lib
MAKE_ENV+=		TOUCH="${TOUCH}"

USE_X11=		yes
USE_LIBTOOL=		yes
USE_BUILDLINK_ONLY=	yes
REPLACE_BUILDLINK+=	tkConfig.sh

# Initially install the man pages into ${WRKDIR}/man, as we need a staged
# install to avoid overwriting existing manpages in ${PREFIX}/man.
#
CONFIGURE_ARGS+=	--mandir=${WRKDIR}/man

# Modify mkLinks script to remove the short-filename manpage if it was
# linked to a longer filename.
#
post-patch:
	@cd ${WRKSRC};							\
	${MV} -f mkLinks mkLinks.tmp;					\
	${GREP} -v "^exit 0" mkLinks.tmp > mkLinks;			\
	${CAT} mkLinks.tmp						\
		| ${AWK} '/^  *ln / { print $$2 }'			\
		| ${SORT} -u						\
		| ${GREP} -v ".*\.n"					\
		| ${SED} -e "s,^,${RM} -f ,"				\
		>> mkLinks;						\
	${RM} -f mkLinks.tmp;						\
	${CHMOD} +x mkLinks;

post-install:
	${CHMOD} -R ugo-w ${WRKDIR}/man
	cd ${WRKDIR}; ${PAX} -rw man ${PREFIX}
	${CHMOD} -R ug+rw ${WRKDIR}/man
	${RM} -f ${PREFIX}/bin/wish
	cd ${PREFIX}/bin && ${LN} -s wish8.3 wish
	${INSTALL_DATA_DIR} ${PREFIX}/include/tk
	${INSTALL_DATA_DIR} ${PREFIX}/include/tk/generic
	${INSTALL_DATA_DIR} ${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/../generic/default.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/ks_names.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tk.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tk3d.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkButton.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkCanvas.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkColor.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkFileFilter.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkFont.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkInitScript.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkInt.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkIntDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkIntPlatDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkIntXlibDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkMenu.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkMenubutton.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkPlatDecls.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkPort.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkScale.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkScrollbar.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkSelect.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../generic/tkText.h ${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/../unix/tkUnixDefault.h ${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/../unix/tkUnixInt.h ${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/../unix/tkUnixPort.h ${PREFIX}/include/tk/unix

test:
	cd ${WRKSRC}; ${SETENV} LIBTOOL=${LIBTOOL} PREFIX=${PREFIX} ${MAKE} test

.include "../../lang/tcl/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
