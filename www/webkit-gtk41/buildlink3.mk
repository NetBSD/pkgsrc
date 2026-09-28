# $NetBSD: buildlink3.mk,v 1.5 2026/09/28 13:46:47 gdt Exp $

BUILDLINK_TREE+=	webkit-gtk41

.if !defined(WEBKIT_GTK41_BUILDLINK3_MK)
WEBKIT_GTK41_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-gtk41+=	webkit-gtk41>=2.52.6
BUILDLINK_ABI_DEPENDS.webkit-gtk41?=	webkit-gtk41>=2.54.0nb1
BUILDLINK_PKGSRCDIR.webkit-gtk41?=	../../www/webkit-gtk41

USE_CXX_FEATURES=	c++23

.include "../../x11/gtk3/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.endif	# WEBKIT_GTK41_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-gtk41
