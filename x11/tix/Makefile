# $NetBSD: Makefile,v 1.2 1998/05/04 22:55:29 tron Exp $
# $FreeBSD Id: Makefile,v 1.15 1998/03/17 07:55:17 tg Exp

DISTNAME=	Tix4.1.0.006
PKGNAME=	tix-4.1.0.006
CATEGORIES=	x11 tk80
MASTER_SITES=	ftp://ftp.xpi.com/pub/

MAINTAINER=	rh@vip.at

DEPENDS+=	tk-8.0p2:../../x11/tk80

WRKSRC=		${WRKDIR}/Tix4.1.0/unix/tk8.0
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-sam \
		--with-tcl="${PREFIX}/include/tcl8.0" \
		--with-tk="${PREFIX}/include/tk8.0"
# this should probably be added to bsd.port.mk
CONFIGURE_ENV+=	PREFIX=${PREFIX}
MAN1=		tixwish.1
MANN=		BtnBox.n Balloon.n ChkList.n Destroy.n ComboBox.n Control.n \
		DItem.n DirDlg.n DirList.n DirTree.n FileBox.n EFileBox.n \
		EFileDlg.n FileDlg.n FileEnt.n Form.n GetBool.n GetInt.n \
		Grid.n HList.n InpOnly.n LabEntry.n Meter.n LabFrame.n \
		ListNBK.n Mwm.n NBFrame.n NoteBook.n SHList.n PopMenu.n \
		OptMenu.n PanedWin.n SListBox.n SText.n SWindow.n TList.n \
		Select.n StdBBox.n TixIntro.n Tree.n Utils.n Wm.n compound.n \
		pixmap.n tix.n

pre-configure:
	@(cd ${WRKSRC}/.. && \
	    CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	    INSTALL="${INSTALL}" INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	  ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	@(cd ${WRKSRC}/.. && \
	    ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	@${MKDIR} ${PREFIX}/man/man1
	@${MV} ${PREFIX}/man/mann/tixwish.1 ${PREFIX}/man/man1
	@${LN} -sf ${PREFIX}/bin/tixwish4.1.8.0 ${PREFIX}/bin/tixwish
	${LDCONFIG} || ${TRUE}
.for dir in generic unix
	@${MKDIR} ${PREFIX}/include/tix/${dir}
	${INSTALL_DATA} ${WRKSRC}/../../${dir}/*.h ${PREFIX}/include/tix/${dir}
.endfor
	${RM} ${PREFIX}/include/tix/generic/tix.h
	@# These two files are the same
	${LN} -sf ../../tix.h ${PREFIX}/include/tix/generic

.include <../../mk/bsd.pkg.mk>
