# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:54:11 dholland Exp $

BUILDLINK_TREE+=	ocaml-graphics

.if !defined(OCAML_GRAPHICS_BUILDLINK3_MK)
OCAML_GRAPHICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-graphics+=	ocaml-graphics>=3.08.2
BUILDLINK_ABI_DEPENDS.ocaml-graphics+=	ocaml-graphics>=3.12.0nb5
BUILDLINK_PKGSRCDIR.ocaml-graphics?=	../../x11/ocaml-graphics

.include "../../lang/ocaml/buildlink3.mk"
.endif # OCAML_GRAPHICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-graphics
