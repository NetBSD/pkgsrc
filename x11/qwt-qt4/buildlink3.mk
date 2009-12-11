# $NetBSD: buildlink3.mk,v 1.1 2009/12/11 19:17:38 drochner Exp $

BUILDLINK_TREE+=	qwt

.if !defined(QWT_BUILDLINK3_MK)
QWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qwt+=	qwt>=5.2.0
BUILDLINK_PKGSRCDIR.qwt?=	../../x11/qwt-qt4

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qwt
