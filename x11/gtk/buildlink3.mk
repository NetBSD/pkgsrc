# $NetBSD: buildlink3.mk,v 1.18 2009/03/20 19:25:41 joerg Exp $

BUILDLINK_TREE+=	gtk

.if !defined(GTK_BUILDLINK3_MK)
GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk+=		gtk+>=1.2.10
BUILDLINK_ABI_DEPENDS.gtk+=	gtk+>=1.2.10nb9
BUILDLINK_PKGSRCDIR.gtk?=	../../x11/gtk

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.endif # GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk
