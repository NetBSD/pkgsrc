# $NetBSD: buildlink3.mk,v 1.3 2013/04/06 13:46:35 rodent Exp $

BUILDLINK_TREE+=	videoproto

.if !defined(VIDEOPROTO_BUILDLINK3_MK)
VIDEOPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.videoproto?=	build

BUILDLINK_API_DEPENDS.videoproto+=	videoproto>=2.2.1
BUILDLINK_PKGSRCDIR.videoproto?=	../../x11/videoproto
.endif # VIDEOPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-videoproto
