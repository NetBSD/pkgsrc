# $NetBSD: buildlink3.mk,v 1.1 2019/07/01 16:06:55 jaapb Exp $

BUILDLINK_TREE+=	ocaml-mtime

.if !defined(OCAML_MTIME_BUILDLINK3_MK)
OCAML_MTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-mtime+=	ocaml-mtime>=1.1.0
BUILDLINK_PKGSRCDIR.ocaml-mtime?=	../../time/ocaml-mtime

.endif	# OCAML_MTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-mtime
