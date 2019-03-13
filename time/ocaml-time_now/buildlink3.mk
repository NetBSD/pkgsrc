# $NetBSD: buildlink3.mk,v 1.1 2019/03/13 11:50:24 jaapb Exp $

BUILDLINK_TREE+=	ocaml-time_now

.if !defined(OCAML_TIME_NOW_BUILDLINK3_MK)
OCAML_TIME_NOW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-time_now+=	ocaml-time_now>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-time_now?=	../../time/ocaml-time_now

.endif	# OCAML_TIME_NOW_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-time_now
