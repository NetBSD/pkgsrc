# $NetBSD: buildlink3.mk,v 1.16 2021/04/09 11:14:54 adam Exp $

BUILDLINK_TREE+=	gtk-mac-integration

.if !defined(GTK_MAC_INTEGRATION_BUILDLINK3_MK)
GTK_MAC_INTEGRATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-mac-integration+=	gtk-mac-integration>=2.0.0
BUILDLINK_ABI_DEPENDS.gtk-mac-integration+=	gtk-mac-integration>=2.0.8nb9
BUILDLINK_PKGSRCDIR.gtk-mac-integration?=	../../x11/gtk-mac-integration

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GTK_MAC_INTEGRATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-mac-integration
