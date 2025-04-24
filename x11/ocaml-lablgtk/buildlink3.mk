# $NetBSD: buildlink3.mk,v 1.65 2025/04/24 14:16:23 wiz Exp $

BUILDLINK_TREE+=	ocaml-lablgtk

.if !defined(OCAML_LABLGTK_BUILDLINK3_MK)
OCAML_LABLGTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lablgtk+=	ocaml-lablgtk>=2.6.0nb3
BUILDLINK_ABI_DEPENDS.ocaml-lablgtk+=	ocaml-lablgtk>=2.18.13nb19
BUILDLINK_PKGSRCDIR.ocaml-lablgtk?=	../../x11/ocaml-lablgtk

.include "../../x11/gtk2/buildlink3.mk"
.endif # OCAML_LABLGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lablgtk
