# $NetBSD: buildlink3.mk,v 1.5 2023/01/03 17:36:33 wiz Exp $

BUILDLINK_TREE+=	mutter

.if !defined(MUTTER_BUILDLINK3_MK)
MUTTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mutter+=	mutter>=40.0
BUILDLINK_ABI_DEPENDS.mutter?=	mutter>=40.2nb3
BUILDLINK_PKGSRCDIR.mutter?=	../../wm/mutter

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/graphene/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# MUTTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mutter
