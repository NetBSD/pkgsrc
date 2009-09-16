# $NetBSD: buildlink3.mk,v 1.17 2009/09/16 01:15:35 reed Exp $

BUILDLINK_TREE+=	xfce4-gtk2-engine

.if !defined(XFCE4_GTK2_ENGINE_BUILDLINK3_MK)
XFCE4_GTK2_ENGINE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-gtk2-engine+=	xfce4-gtk2-engine>=2.6.0
BUILDLINK_PKGSRCDIR.xfce4-gtk2-engine?=	../../x11/xfce4-gtk2-engine

.endif # XFCE4_GTK2_ENGINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-gtk2-engine
