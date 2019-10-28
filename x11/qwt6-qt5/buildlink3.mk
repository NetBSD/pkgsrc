# $NetBSD: buildlink3.mk,v 1.1 2019/10/28 19:00:37 bouyer Exp $

BUILDLINK_TREE+=	qwt6-qt5

.if !defined(QWT_BUILDLINK3_MK)
QWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qwt6-qt5+= qwt6-qt5>=6.1.4
BUILDLINK_ABI_DEPENDS.qwt6-qt5+= qwt6-qt5>=6.1.4
BUILDLINK_PKGSRCDIR.qwt6-qt5?=	../../x11/qwt6-qt5

QWT_DIR=			${BUILDLINK_PREFIX.qwt6-qt5}/qwt-6.1.4
BUILDLINK_INCDIRS.qwt6-qt5+=	qwt-6.1.4/include
BUILDLINK_LIBDIRS.qwt6-qt5+=	qwt-6.1.4/lib
BUILDLINK_RPATHDIRS.qwt6-qt5+=	qwt-6.1.4/lib

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.endif	# QWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qwt6-qt5
