# $NetBSD: Makefile,v 1.21 1998/06/07 19:40:30 frueauf Exp $
# FreeBSD Id: Makefile,v 1.13 1997/09/08 08:34:13 tg Exp
#

DISTNAME=	lesstif-0.85
CATEGORIES=	x11
MASTER_SITES=	ftp://linux.gt.ed.net/pub/linux/libs/lesstif/srcdist/ \
		ftp://ftp.mathematik.th-darmstadt.de/pub/linux/mirrors/misc/lesstif/srcdist/ \
		ftp://ftp.lesstif.org/pub/hungry/lesstif/srcdist/

MAINTAINER=	packages@netbsd.org

CONFLICTS=	lesstif-0.82 lesstif-0.83 lesstif-0.84 lesstif-19980510

GNU_CONFIGURE=  yes
USE_X11=	yes
# change this for debugging
CONFIGURE_ENV=	CCFLAGS="-O -pipe" INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		VarHaveMan2html=0

MAN1=		mwm.1 xmbind.1 lesstif.1
MAN3=		XmClipboard.3 LessTifInternals.3 XmArrowButton.3\
		XmArrowButtonGadget.3 XmBulletinBoard.3 XmCascadeButton.3\
		XmCascadeButtonGCacheObj.3 XmCascadeButtonGadget.3\
		XmComboBox.3 XmCommand.3 XmDesktop.3 XmDialogShell.3\
		XmDialogShellExt.3 XmDisplay.3 XmDragContext.3 XmDragIcon.3\
		XmDragOverShell.3 XmDrawingArea.3 XmForm.3 XmDrawnButton.3\
		XmDropSiteManager.3 XmDropTransfer.3 XmFileSelectionBox.3\
		XmFrame.3 XmGadget.3 XmGrabShell.3 XmIconGCacheObj.3\
		XmIconGadget.3 XmLabel.3 XmLabelGCacheObj.3 XmLabelGadget.3\
		XmList.3 XmMainWindow.3 XmManager.3 XmMenuShell.3\
		XmMessageBox.3 XmNotebook.3 XmPanedWindow.3 XmPrimitive.3\
		XmProtocol.3 XmPushButton.3 XmPushButtonGCacheObj.3\
		XmPushButtonGadget.3 XmRowColumn.3 XmSash.3 XmScale.3\
		XmScreen.3 XmScrollBar.3 XmScrolledWindow.3 XmSelectionBox.3\
		XmSeparator.3 XmSeparatorGCacheObj.3 XmSeparatorGadget.3\
		XmSpinBox.3 XmTearOffButton.3 XmText.3 XmTextField.3\
		XmToggleButton.3 XmToggleButtonGCacheObj.3 XmWorld.3\
		XmToggleButtonGadget.3 XmVendorShellExt.3
MAN5=		mwmrc.5

pre-fetch:
	@if [ -d ${X11BASE}/include/Xm ]; then 				\
		if [ -d ${X11BASE}/lib/X11/lesstif ]; then 		\
			${ECHO} "Upgrading a previous Lesstif installation"; \
			return 0; 					\
		fi; 							\
		${ECHO} "Motif is already installed in ${X11BASE}";	\
		${ECHO} "To install lesstif, first delete Motif from ${X11BASE}"; \
		return 1;						\
	fi

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
