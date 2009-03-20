# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:25:48 joerg Exp $

BUILDLINK_TREE+=	openmotif

.if !defined(OPENMOTIF_BUILDLINK3_MK)
OPENMOTIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmotif+=	openmotif>=2.3.1
BUILDLINK_ABI_DEPENDS.openmotif?=	openmotif>=2.3.1
BUILDLINK_PKGSRCDIR.openmotif?=	../../x11/openmotif

.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.endif # OPENMOTIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmotif
