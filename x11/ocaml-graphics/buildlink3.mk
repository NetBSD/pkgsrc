# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:48 joerg Exp $

BUILDLINK_TREE+=	ocaml-graphics

.if !defined(OCAML_GRAPHICS_BUILDLINK3_MK)
OCAML_GRAPHICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-graphics+=	ocaml-graphics>=3.08.2
BUILDLINK_ABI_DEPENDS.ocaml-graphics?=	ocaml-graphics>=3.09.1
BUILDLINK_PKGSRCDIR.ocaml-graphics?=	../../x11/ocaml-graphics

.include "../../lang/ocaml/buildlink3.mk"
.endif # OCAML_GRAPHICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-graphics
