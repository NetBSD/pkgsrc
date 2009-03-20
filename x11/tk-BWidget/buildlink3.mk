# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:51 joerg Exp $
#

BUILDLINK_TREE+=	tk-BWidget

.if !defined(TK_BWIDGET_BUILDLINK3_MK)
TK_BWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk-BWidget+=	tk-BWidget>=1.7.0
BUILDLINK_ABI_DEPENDS.tk-BWidget?=	tk-BWidget>=1.7.0nb1
BUILDLINK_PKGSRCDIR.tk-BWidget?=	../../x11/tk-BWidget
.endif # TK_BWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk-BWidget
