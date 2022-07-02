# $NetBSD: buildlink3.mk,v 1.57 2022/07/02 16:53:42 ryoon Exp $

BUILDLINK_TREE+=	qt5-qttools

.if !defined(QT5_QTTOOLS_BUILDLINK3_MK)
QT5_QTTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qttools+=	qt5-qttools>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qttools+=	qt5-qttools>=5.15.5nb1
BUILDLINK_PKGSRCDIR.qt5-qttools?=	../../x11/qt5-qttools

BUILDLINK_INCDIRS.qt5-qttools+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qttools+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qttools+=	qt5/plugins

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/assistant
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/designer
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/linguist
.endif

.include "../../x11/qt5-qtbase/buildlink3.mk"

.if ${PKG_BUILD_OPTIONS.qt5-qtbase:Mdbus}
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/qdbus
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/qdbusviewer
.endif


pkgbase:= qt5-qttools

.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.qt5-qttools:Mllvm}
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/qdoc
.endif


BUILDLINK_FILES.qt5-qttools+=	qt5/bin/lconvert
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/lprodump
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/lrelease
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/lrelease-pro
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/lupdate
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/lupdate-pro
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/pixeltool
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/qcollectiongenerator
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/qdistancefieldgenerator
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/qhelpgenerator
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/qtattributionsscanner
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/qtdiag
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/qtpaths
BUILDLINK_FILES.qt5-qttools+=	qt5/bin/qtplugininfo

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
#.include "../../x11/qt5-qtwebkit/buildlink3.mk"
#instead:
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.endif	# QT5_QTTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qttools
