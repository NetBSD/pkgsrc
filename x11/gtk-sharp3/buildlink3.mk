# $NetBSD: buildlink3.mk,v 1.1 2020/01/26 13:52:55 nia Exp $

BUILDLINK_TREE+=	gtk-sharp

.if !defined(GTK_SHARP_BUILDLINK3_MK)
GTK_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-sharp+=	gtk-sharp>=2.99.3
BUILDLINK_PKGSRCDIR.gtk-sharp?=		../../x11/gtk-sharp3
.endif	# GTK_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-sharp
