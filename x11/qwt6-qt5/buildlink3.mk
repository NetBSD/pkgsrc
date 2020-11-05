# $NetBSD: buildlink3.mk,v 1.11 2020/11/05 09:07:22 ryoon Exp $

BUILDLINK_TREE+=	qwt6-qt5

.if !defined(QWT6_QT5_BUILDLINK3_MK)
QWT6_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qwt6-qt5+=	qwt6-qt5>=6.1.5
BUILDLINK_ABI_DEPENDS.qwt6-qt5?=		qwt6-qt5>=6.1.5nb2
BUILDLINK_PKGSRCDIR.qwt6-qt5?=		../../x11/qwt6-qt5

QWT_DIR=			${BUILDLINK_PREFIX.qwt6-qt5}/qwt-6.1.5
BUILDLINK_INCDIRS.qwt6-qt5+=	qwt-6.1.5/include
BUILDLINK_LIBDIRS.qwt6-qt5+=	qwt-6.1.5/lib
BUILDLINK_RPATHDIRS.qwt6-qt5+=	qwt-6.1.5/lib

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.endif	# QWT6_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-qwt6-qt5
