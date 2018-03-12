# $NetBSD: buildlink3.mk,v 1.31 2018/03/12 11:15:57 wiz Exp $

BUILDLINK_TREE+=	qt5-qttools

.if !defined(QT5_QTTOOLS_BUILDLINK3_MK)
QT5_QTTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qttools+=	qt5-qttools>=5.9.1
BUILDLINK_ABI_DEPENDS.qt5-qttools+=	qt5-qttools>=5.10.1nb1
BUILDLINK_PKGSRCDIR.qt5-qttools?=	../../x11/qt5-qttools

BUILDLINK_INCDIRS.qt5-qttools+=	qt5/include
BUILDLINK_LIBDIRS.qt5-qttools+=	qt5/lib
BUILDLINK_LIBDIRS.qt5-qttools+=	qt5/plugins

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
