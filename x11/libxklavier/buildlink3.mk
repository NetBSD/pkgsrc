# $NetBSD: buildlink3.mk,v 1.15 2009/03/20 19:25:47 joerg Exp $

BUILDLINK_TREE+=	libxklavier

.if !defined(LIBXKLAVIER_BUILDLINK3_MK)
LIBXKLAVIER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=3.0
BUILDLINK_PKGSRCDIR.libxklavier?=	../../x11/libxklavier

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.endif # LIBXKLAVIER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxklavier
