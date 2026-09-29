# $NetBSD: buildlink3.mk,v 1.4 2026/09/29 06:08:10 wiz Exp $

BUILDLINK_TREE+=	webkit-gtk60

.if !defined(WEBKIT_GTK60_BUILDLINK3_MK)
WEBKIT_GTK60_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-gtk60+=	webkit-gtk60>=2.50.6
BUILDLINK_ABI_DEPENDS.webkit-gtk60?=	webkit-gtk60>=2.54.0nb2
BUILDLINK_PKGSRCDIR.webkit-gtk60?=	../../www/webkit-gtk60

GCC_REQD+=	11

.include "../../net/libsoup3/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif # WEBKIT_GTK60_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-gtk60
