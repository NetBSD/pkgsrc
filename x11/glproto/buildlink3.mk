# $NetBSD: buildlink3.mk,v 1.3 2013/04/06 13:46:34 rodent Exp $

BUILDLINK_TREE+=	glproto

.if !defined(GLPROTO_BUILDLINK3_MK)
GLPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.glproto?=	build

BUILDLINK_API_DEPENDS.glproto+=	glproto>=1.4.6
BUILDLINK_PKGSRCDIR.glproto?=	../../x11/glproto
.endif # GLPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-glproto
