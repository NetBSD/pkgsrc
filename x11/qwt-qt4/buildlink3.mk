# $NetBSD: buildlink3.mk,v 1.20 2013/02/06 23:21:15 jperkin Exp $

BUILDLINK_TREE+=	qwt

.if !defined(QWT_BUILDLINK3_MK)
QWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qwt+=	qwt>=5.2.0
BUILDLINK_ABI_DEPENDS.qwt+=	qwt>=5.2.2nb10
BUILDLINK_PKGSRCDIR.qwt?=	../../x11/qwt-qt4

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qwt
