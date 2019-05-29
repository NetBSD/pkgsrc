# $NetBSD: buildlink3.mk,v 1.2 2019/05/29 19:52:48 adam Exp $

BUILDLINK_TREE+=	slop

.if !defined(SLOP_BUILDLINK3_MK)
SLOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.slop+=	slop>=7.4
BUILDLINK_ABI_DEPENDS.slop?=	slop>=7.4nb3
BUILDLINK_PKGSRCDIR.slop?=	../../x11/slop

.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.endif	# SLOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-slop
