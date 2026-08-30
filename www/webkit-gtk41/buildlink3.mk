# $NetBSD: buildlink3.mk,v 1.1 2026/08/30 14:25:05 wiz Exp $

BUILDLINK_TREE+=	webkit-gtk41

.if !defined(WEBKIT_GTK41_BUILDLINK3_MK)
WEBKIT_GTK41_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-gtk41+=	webkit-gtk41>=2.52.6
BUILDLINK_PKGSRCDIR.webkit-gtk41?=	../../www/webkit-gtk41

GCC_REQD+=	11

.include "../../x11/gtk3/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.endif	# WEBKIT_GTK41_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-gtk41
