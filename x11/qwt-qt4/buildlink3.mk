# $NetBSD: buildlink3.mk,v 1.9 2011/11/01 06:03:08 sbd Exp $

BUILDLINK_TREE+=	qwt

.if !defined(QWT_BUILDLINK3_MK)
QWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qwt+=	qwt>=6.0.0
BUILDLINK_ABI_DEPENDS.qwt+=	qwt>=6.0.0nb2
BUILDLINK_PKGSRCDIR.qwt?=	../../x11/qwt-qt4

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qwt
