# $NetBSD: buildlink3.mk,v 1.3 2022/05/11 14:16:37 jaapb Exp $

BUILDLINK_TREE+=	ocaml-cohttp

.if !defined(OCAML_COHTTP_BUILDLINK3_MK)
OCAML_COHTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-cohttp+=	ocaml-cohttp>=5.0.0
BUILDLINK_ABI_DEPENDS.ocaml-cohttp+=	ocaml-cohttp>=5.0.0
BUILDLINK_PKGSRCDIR.ocaml-cohttp?=	../../www/ocaml-cohttp

.endif	# OCAML_COHTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-cohttp
