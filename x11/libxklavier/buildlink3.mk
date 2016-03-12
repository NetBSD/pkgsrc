# $NetBSD: buildlink3.mk,v 1.20 2016/03/12 11:12:40 ryoon Exp $

BUILDLINK_TREE+=	libxklavier

.if !defined(LIBXKLAVIER_BUILDLINK3_MK)
LIBXKLAVIER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=3.0
BUILDLINK_ABI_DEPENDS.libxklavier+=	libxklavier>=5.4
BUILDLINK_PKGSRCDIR.libxklavier?=	../../x11/libxklavier

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.endif # LIBXKLAVIER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxklavier
