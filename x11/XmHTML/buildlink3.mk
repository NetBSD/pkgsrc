# $NetBSD: buildlink3.mk,v 1.14 2010/12/23 11:44:59 dsainty Exp $

BUILDLINK_TREE+=	XmHTML

.if !defined(XMHTML_BUILDLINK3_MK)
XMHTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.XmHTML+=	XmHTML>=1.1.7nb2
BUILDLINK_ABI_DEPENDS.XmHTML+=	XmHTML>=1.1.7nb9
BUILDLINK_PKGSRCDIR.XmHTML?=	../../x11/XmHTML

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # XMHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-XmHTML
