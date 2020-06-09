# $NetBSD: buildlink3.mk,v 1.8 2020/06/09 07:01:55 mef Exp $

BUILDLINK_TREE+=	qwt6-qt5

.if !defined(QWT6_QT5_BUILDLINK3_MK)
QWT6_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qwt6-qt5+=	qwt6-qt5>=6.1.4
BUILDLINK_ABI_DEPENDS.qwt6-qt5+=	qwt6-qt5>=6.1.4nb5
BUILDLINK_PKGSRCDIR.qwt6-qt5?=		../../x11/qwt6-qt5

QWT_DIR=			${BUILDLINK_PREFIX.qwt6-qt5}/qwt-6.1.4
BUILDLINK_INCDIRS.qwt6-qt5+=	qwt-6.1.4/include
BUILDLINK_LIBDIRS.qwt6-qt5+=	qwt-6.1.4/lib
BUILDLINK_RPATHDIRS.qwt6-qt5+=	qwt-6.1.4/lib

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.endif	# QWT6_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-qwt6-qt5
