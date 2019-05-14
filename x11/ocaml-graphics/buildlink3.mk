# $NetBSD: buildlink3.mk,v 1.25 2019/05/14 16:01:17 jaapb Exp $

BUILDLINK_TREE+=	ocaml-graphics

.if !defined(OCAML_GRAPHICS_BUILDLINK3_MK)
OCAML_GRAPHICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-graphics+=	ocaml-graphics>=2.0.0
BUILDLINK_PKGSRCDIR.ocaml-graphics?=	../../x11/ocaml-graphics

.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# OCAML_GRAPHICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-graphics
