# $NetBSD: buildlink3.mk,v 1.6 2022/06/28 11:37:53 wiz Exp $

BUILDLINK_TREE+=	gtk-sharp

.if !defined(GTK_SHARP_BUILDLINK3_MK)
GTK_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-sharp+=	gtk-sharp>=2.12.1
BUILDLINK_ABI_DEPENDS.gtk-sharp?=		gtk-sharp>=2.12.45nb12
BUILDLINK_PKGSRCDIR.gtk-sharp?=		../../x11/gtk-sharp
.endif # GTK_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-sharp
