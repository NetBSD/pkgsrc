# $NetBSD: buildlink3.mk,v 1.3 2013/04/06 13:46:34 rodent Exp $

BUILDLINK_TREE+=	bigreqsproto

.if !defined(BIGREQSPROTO_BUILDLINK3_MK)
BIGREQSPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.bigreqsproto?=	build

BUILDLINK_API_DEPENDS.bigreqsproto+=	bigreqsproto>=1.0
BUILDLINK_PKGSRCDIR.bigreqsproto?=	../../x11/bigreqsproto
.endif # BIGREQSPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-bigreqsproto
