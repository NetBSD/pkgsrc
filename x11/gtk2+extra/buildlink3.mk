# $NetBSD: buildlink3.mk,v 1.24 2012/10/08 23:00:48 adam Exp $

BUILDLINK_TREE+=	gtk2+extra

.if !defined(GTK2_EXTRA_BUILDLINK3_MK)
GTK2_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk2+extra+=	gtk2+extra>=2.1.1
BUILDLINK_ABI_DEPENDS.gtk2+extra+=	gtk2+extra>=2.1.2nb12
BUILDLINK_PKGSRCDIR.gtk2+extra?=	../../x11/gtk2+extra

.include "../../x11/gtk2/buildlink3.mk"
.endif # GTK2_EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk2+extra
