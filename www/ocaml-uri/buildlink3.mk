# $NetBSD: buildlink3.mk,v 1.3 2020/04/21 11:21:47 jaapb Exp $

BUILDLINK_TREE+=	ocaml-uri

.if !defined(OCAML_URI_BUILDLINK3_MK)
OCAML_URI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-uri+=	ocaml-uri>=3.0.0
BUILDLINK_ABI_DEPENDS.ocaml-uri+=	ocaml-uri>=3.1.0
BUILDLINK_PKGSRCDIR.ocaml-uri?=		../../www/ocaml-uri

.endif	# OCAML_URI_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-uri
