# $NetBSD: buildlink3.mk,v 1.18 2025/10/23 20:39:42 wiz Exp $

BUILDLINK_TREE+=	mutter

.if !defined(MUTTER_BUILDLINK3_MK)
MUTTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mutter+=	mutter>=40.0
BUILDLINK_ABI_DEPENDS.mutter?=	mutter>=40.2nb16
BUILDLINK_PKGSRCDIR.mutter?=	../../wm/mutter

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# MUTTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mutter
