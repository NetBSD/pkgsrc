# $NetBSD: buildlink3.mk,v 1.20 2023/01/29 21:15:06 ryoon Exp $

BUILDLINK_TREE+=	gtk-mac-integration

.if !defined(GTK_MAC_INTEGRATION_BUILDLINK3_MK)
GTK_MAC_INTEGRATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-mac-integration+=	gtk-mac-integration>=2.0.0
BUILDLINK_ABI_DEPENDS.gtk-mac-integration+=	gtk-mac-integration>=3.0.1nb4
BUILDLINK_PKGSRCDIR.gtk-mac-integration?=	../../x11/gtk-mac-integration

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GTK_MAC_INTEGRATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-mac-integration
