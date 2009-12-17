# $NetBSD: Makefile,v 1.18 2009/12/17 18:23:49 abs Exp $

DISTNAME=	tk8.3.4
PKGNAME=	tk-8.3.4
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.informatik.uni-hamburg.de/pub/soft/lang/tcl/tcl8_3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcltk.com/
COMMENT=	Graphical toolkit for TCL

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT= 	user-destdir
INSTALLATION_DIRS+=	include/tk/generic include/tk/unix

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}/lib

SUBST_CLASSES+=		tk834
SUBST_STAGE.tk834=	post-build
SUBST_FILES.tk834=	unix/tkConfig.sh
SUBST_SED.tk834+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tk834+=	-e "s|${WRKSRC}|${PREFIX}/include/tk|"

MAKE_ENV+=		TOUCH=${TOUCH:Q}

USE_LIBTOOL=		yes
TEST_TARGET=		test

.include "../../mk/bsd.prefs.mk"

.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

# Modify mkLinks script to remove the short-filename manpage if it was
# linked to a longer filename.
#
post-patch:
	cd ${WRKSRC}/unix;						\
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

post-build:
	cd ${WRKSRC}/unix; for file in					\
		tkUnixInit.o libtk83.so wish;				\
	do								\
		${TOUCH} $${file};					\
	done

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s wish8.3 wish
	${INSTALL_DATA} ${WRKSRC}/generic/default.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/ks_names.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tk.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tk3d.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkButton.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkCanvas.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkColor.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkDecls.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkFileFilter.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkFont.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkInitScript.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkInt.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntDecls.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntPlatDecls.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkIntXlibDecls.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkMenu.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkMenubutton.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkPlatDecls.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkPort.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkScale.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkScrollbar.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkSelect.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/generic/tkText.h ${DESTDIR}${PREFIX}/include/tk/generic
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixDefault.h ${DESTDIR}${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixInt.h ${DESTDIR}${PREFIX}/include/tk/unix
	${INSTALL_DATA} ${WRKSRC}/unix/tkUnixPort.h ${DESTDIR}${PREFIX}/include/tk/unix

.include "../../lang/tcl83/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
