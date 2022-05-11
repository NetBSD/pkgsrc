# $NetBSD: buildlink3.mk,v 1.4 2022/05/11 10:27:50 jaapb Exp $

BUILDLINK_TREE+=	ocaml-uri

.if !defined(OCAML_URI_BUILDLINK3_MK)
OCAML_URI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-uri+=	ocaml-uri>=3.0.0
BUILDLINK_ABI_DEPENDS.ocaml-uri+=	ocaml-uri>=4.2.0
BUILDLINK_PKGSRCDIR.ocaml-uri?=		../../www/ocaml-uri

.endif	# OCAML_URI_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-uri
