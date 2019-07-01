# $NetBSD: buildlink3.mk,v 1.1 2019/07/01 15:48:53 jaapb Exp $

BUILDLINK_TREE+=	ocaml-cohttp

.if !defined(OCAML_COHTTP_BUILDLINK3_MK)
OCAML_COHTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-cohttp+=	ocaml-cohttp>=2.1.2
BUILDLINK_PKGSRCDIR.ocaml-cohttp?=	../../www/ocaml-cohttp

.endif	# OCAML_COHTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-cohttp
