# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 14:26:38 jaapb Exp $

BUILDLINK_TREE+=	ocaml-uri

.if !defined(OCAML_URI_BUILDLINK3_MK)
OCAML_URI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-uri+=	ocaml-uri>=2.2.0
BUILDLINK_PKGSRCDIR.ocaml-uri?=	../../www/ocaml-uri

.endif	# OCAML_URI_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-uri
