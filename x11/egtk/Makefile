# $NetBSD: Makefile,v 1.2 1999/10/14 02:30:25 jlam Exp $
#

DISTNAME=	eiffel_gtk_0.3.3
PKGNAME=	egtk-0.3.3
CATEGORIES=	x11
MASTER_SITES=	http://www.netlabs.net/hp/richieb/downloads/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.netlabs.net/hp/richieb/gtk_eiffel.html

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	smalleiffel-*:../../lang/smalleiffel

USE_X11=	yes

WRKSRC=		${WRKDIR}/eGTK

post-extract:
	find ${WRKSRC} -type d -name "CVS" -print | xargs ${RM} -rf
	find ${WRKSRC} -type d -name "ise" -print | xargs ${RM} -rf
	find ${WRKSRC} -type f -name "*.ace" -print | xargs ${RM} -f
	find ${WRKSRC} -type f -name "*.orig" -print | xargs ${RM} -f
	find ${WRKSRC} -type f -name "*.rej" -print | xargs ${RM} -f
	${RMDIR} ${WRKSRC}/lib/gdk/se ${WRKSRC}/examples/toolbar
	${RM} ${WRKSRC}/examples/Makefile
	cd ${WRKSRC}/C/se; ${MAKE_PROGRAM} -f Makefile.se clean
	${MV} ${WRKSRC}/bin/egtkbuild ${WRKSRC}/bin/egtkbuild.in
	${MV} ${WRKSRC}/man/egtkbuild.1 ${WRKSRC}/man/egtkbuild.1.in

do-configure:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		${WRKSRC}/bin/egtkbuild.in > ${WRKSRC}/bin/egtkbuild
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		${WRKSRC}/man/egtkbuild.1.in > ${WRKSRC}/man/egtkbuild.1
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		${FILESDIR}/loadpath.se.in > ${WRKDIR}/loadpath.se

do-build:
	cd ${WRKSRC}/C/se; ${MAKE_PROGRAM} ${MAKE_FLAGS} -f Makefile.se

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/egtkbuild ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/man/egtkbuild.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/C/se/eif_gtk.a ${PREFIX}/lib/libegtk_se.a
	${INSTALL_DATA_DIR} ${PREFIX}/share/egtk
	cd ${WRKSRC}/lib; ${PAX} -rw * ${PREFIX}/share/egtk
	cd ${WRKSRC}; ${PAX} -rw pixmaps ${PREFIX}/share/egtk
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/egtk
	${INSTALL_DATA_DIR} ${PREFIX}/share/egtk/se
	${INSTALL_DATA} ${WRKSRC}/C/se/cecil.se ${PREFIX}/share/egtk/se
	${INSTALL_DATA} ${WRKSRC}/C/se/eif_gtk_se.c ${PREFIX}/share/egtk/se
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/egtk
	cd ${WRKSRC}/examples; ${PAX} -rw * ${PREFIX}/share/examples/egtk
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/egtk

post-install:
	cd ${WRKSRC}; ${INSTALL_DATA} copyright forum.txt ${PREFIX}/share/egtk
	${INSTALL_DATA} ${WRKDIR}/loadpath.se ${PREFIX}/share/egtk/se

.include "../../mk/bsd.pkg.mk"
