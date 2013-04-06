# $NetBSD: buildlink3.mk,v 1.3 2013/04/06 13:46:34 rodent Exp $

BUILDLINK_TREE+=	evieext

.if !defined(EVIEEXT_BUILDLINK3_MK)
EVIEEXT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.evieext?=	build

BUILDLINK_API_DEPENDS.evieext+=	evieext>=1.0.2
BUILDLINK_PKGSRCDIR.evieext?=	../../x11/evieext
.endif # EVIEEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-evieext
