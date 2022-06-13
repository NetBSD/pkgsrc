# $NetBSD: buildlink3.mk,v 1.1 2022/06/13 08:01:03 jaapb Exp $

BUILDLINK_TREE+=	ocaml-mirage-clock

.if !defined(OCAML_MIRAGE_CLOCK_BUILDLINK3_MK)
OCAML_MIRAGE_CLOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-mirage-clock+=	ocaml-mirage-clock>=4.2.0
BUILDLINK_PKGSRCDIR.ocaml-mirage-clock?=	../../time/ocaml-mirage-clock

.endif	# OCAML_MIRAGE_CLOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-mirage-clock
