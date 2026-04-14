# $NetBSD: buildlink3.mk,v 1.1 2026/04/14 12:41:02 kikadf Exp $

BUILDLINK_TREE+=	gtk-layer-shell

.if !defined(GTK_LAYER_SHELL_BUILDLINK3_MK)
GTK_LAYER_SHELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-layer-shell+=	gtk-layer-shell>=0.10.1
BUILDLINK_ABI_DEPENDS.gtk-layer-shell+=	gtk-layer-shell>=0.10.1
BUILDLINK_PKGSRCDIR.gtk-layer-shell?=	../../wayland/gtk-layer-shell

.endif # GTK_LAYER_SHELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-layer-shell
