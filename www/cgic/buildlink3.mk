# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:36 joerg Exp $

BUILDLINK_TREE+=	cgic

.if !defined(CGIC_BUILDLINK3_MK)
CGIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cgic+=	cgic>=2.02nb1
BUILDLINK_PKGSRCDIR.cgic?=	../../www/cgic
.endif # CGIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-cgic
