# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/05/11 04:29:18 adam Exp $

BUILDLINK_TREE+=	c-icap

.if !defined(C_ICAP_BUILDLINK3_MK)
C_ICAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.c-icap+=	c-icap>=0.1.5
BUILDLINK_PKGSRCDIR.c-icap?=	../../www/c-icap

.include "../../devel/zlib/buildlink3.mk"
.endif	# C_ICAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-c-icap
