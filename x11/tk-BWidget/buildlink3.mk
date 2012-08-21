# $NetBSD: buildlink3.mk,v 1.9 2012/08/21 23:49:27 marino Exp $
#

BUILDLINK_TREE+=	tk-BWidget

.if !defined(TK_BWIDGET_BUILDLINK3_MK)
TK_BWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk-BWidget+=	tk-BWidget>=1.9.0
BUILDLINK_ABI_DEPENDS.tk-BWidget+=	tk-BWidget>=1.9.0nb1
BUILDLINK_PKGSRCDIR.tk-BWidget?=	../../x11/tk-BWidget
.endif # TK_BWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk-BWidget
