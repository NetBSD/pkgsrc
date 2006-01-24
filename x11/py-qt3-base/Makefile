# $NetBSD: Makefile,v 1.20 2006/01/24 07:32:59 wiz Exp $
#

.include "../../x11/py-qt3-base/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-qt3-base-${PYQT_VERSION}
PKGREVISION=		1

COMMENT=		Python binding for Qt3

BUILDLINK_DEPENDS.qt3-tools+=	qt3-tools>=3.1.2nb2

PLIST_SRC=		${PKGDIR}/PLIST.common
.if ${OPSYS} == "Darwin"
PLIST_SRC+=		${PKGDIR}/PLIST.Darwin
.else
PLIST_SRC+=		${PKGDIR}/PLIST.X11
.endif
PLIST_SRC+=		${PKGDIR}/PLIST.common_end

SUBST_CLASSES+=		pyversfx
SUBST_STAGE.pyversfx=	pre-configure
SUBST_FILES.pyversfx=	pyuic3/pyuic.sbf pylupdate3/pylupdate.sbf
SUBST_SED.pyversfx=	-e "s|@PYVERSSUFFIX@|${PYVERSSUFFIX}|g"

.include "../../x11/py-qt3-sip/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/bsd.pkg.mk"
