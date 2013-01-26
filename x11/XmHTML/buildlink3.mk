# $NetBSD: buildlink3.mk,v 1.16 2013/01/26 21:36:51 adam Exp $

BUILDLINK_TREE+=	XmHTML

.if !defined(XMHTML_BUILDLINK3_MK)
XMHTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.XmHTML+=	XmHTML>=1.1.7nb2
BUILDLINK_ABI_DEPENDS.XmHTML+=	XmHTML>=1.1.7nb13
BUILDLINK_PKGSRCDIR.XmHTML?=	../../x11/XmHTML

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif # XMHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-XmHTML
