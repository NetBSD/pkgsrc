# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 09:19:34 jaapb Exp $

BUILDLINK_TREE+=	ocaml-timezone

.if !defined(OCAML_TIMEZONE_BUILDLINK3_MK)
OCAML_TIMEZONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-timezone+=	ocaml-timezone>=0.14.0
BUILDLINK_ABI_DEPENDS.ocaml-timezone+=	ocaml-timezone>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-timezone?=	../../time/ocaml-timezone

.endif	# OCAML_TIMEZONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-timezone
