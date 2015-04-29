# $NetBSD: buildlink3.mk,v 1.1 2015/04/29 09:37:40 jaapb Exp $

BUILDLINK_TREE+=	ocaml-calendar

.if !defined(OCAML_CALENDAR_BUILDLINK3_MK)
OCAML_CALENDAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-calendar+=	ocaml-calendar>=2.03.2nb4
BUILDLINK_PKGSRCDIR.ocaml-calendar?=	../../time/ocaml-calendar

#.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAML_CALENDAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-calendar
