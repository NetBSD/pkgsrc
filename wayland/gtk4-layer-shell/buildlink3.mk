# $NetBSD: buildlink3.mk,v 1.1 2026/04/14 13:05:21 kikadf Exp $

BUILDLINK_TREE+=	gtk4-layer-shell

.if !defined(GTK4_LAYER_SHELL_BUILDLINK3_MK)
GTK4_LAYER_SHELL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk4-layer-shell+=	gtk4-layer-shell>=1.3.0
BUILDLINK_ABI_DEPENDS.gtk4-layer-shell+=	gtk4-layer-shell>=1.3.0
BUILDLINK_PKGSRCDIR.gtk4-layer-shell?=		../../wayland/gtk4-layer-shell

.endif # GTK4_LAYER_SHELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk4-layer-shell
