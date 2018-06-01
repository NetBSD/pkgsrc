# $NetBSD: buildlink3.mk,v 1.1 2018/06/01 17:10:50 youri Exp $

BUILDLINK_TREE+=	libgnomekbd2

.if !defined(LIBGNOMEKBD2_BUILDLINK3_MK)
LIBGNOMEKBD2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomekbd2+=	libgnomekbd2>=2.18.0
BUILDLINK_ABI_DEPENDS.libgnomekbd2+=	libgnomekbd2>=2.32.0nb19
BUILDLINK_PKGSRCDIR.libgnomekbd2?=	../../x11/libgnomekbd2

.include "../../x11/libxklavier/buildlink3.mk"
.endif # LIBGNOMEKBD2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomekbd2
