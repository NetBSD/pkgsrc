# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:25:47 joerg Exp $

BUILDLINK_TREE+=	Mowitz

.if !defined(MOWITZ_BUILDLINK3_MK)
MOWITZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Mowitz+=	Mowitz>=0.3.0
BUILDLINK_PKGSRCDIR.Mowitz?=	../../x11/mowitz

.include "../../x11/libXpm/buildlink3.mk"
.endif # MOWITZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-Mowitz
