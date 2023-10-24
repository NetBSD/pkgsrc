# $NetBSD: buildlink3.mk,v 1.19 2023/10/24 22:11:50 wiz Exp $

BUILDLINK_TREE+=	qwt

.if !defined(QWT_BUILDLINK3_MK)
QWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qwt+=	qwt>=6.0.1
BUILDLINK_ABI_DEPENDS.qwt+=	qwt>=6.0.1nb21
BUILDLINK_PKGSRCDIR.qwt?=	../../x11/qwt6-qt4

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qwt
