# $NetBSD: buildlink3.mk,v 1.4 2016/08/03 10:22:21 adam Exp $

BUILDLINK_TREE+=	gtk-mac-integration

.if !defined(GTK_MAC_INTEGRATION_BUILDLINK3_MK)
GTK_MAC_INTEGRATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk-mac-integration+=	gtk-mac-integration>=2.0.0
BUILDLINK_ABI_DEPENDS.gtk-mac-integration?=	gtk-mac-integration>=2.0.5nb3
BUILDLINK_PKGSRCDIR.gtk-mac-integration?=	../../x11/gtk-mac-integration

.include "../../x11/gtk2/buildlink3.mk"
.endif	# GTK_MAC_INTEGRATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk-mac-integration
