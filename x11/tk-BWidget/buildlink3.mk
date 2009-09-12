# $NetBSD: buildlink3.mk,v 1.8 2009/09/12 20:49:44 plunky Exp $
#

BUILDLINK_TREE+=	tk-BWidget

.if !defined(TK_BWIDGET_BUILDLINK3_MK)
TK_BWIDGET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tk-BWidget+=	tk-BWidget>=1.9.0
BUILDLINK_ABI_DEPENDS.tk-BWidget+=	tk-BWidget>=1.9.0
BUILDLINK_PKGSRCDIR.tk-BWidget?=	../../x11/tk-BWidget
.endif # TK_BWIDGET_BUILDLINK3_MK

BUILDLINK_TREE+=	-tk-BWidget
