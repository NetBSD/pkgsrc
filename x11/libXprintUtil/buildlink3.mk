# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:45 joerg Exp $

BUILDLINK_TREE+=	libXprintUtil

.if !defined(LIBXPRINTUTIL_BUILDLINK3_MK)
LIBXPRINTUTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libXprintUtil+=	libXprintUtil>=1.0.1
BUILDLINK_PKGSRCDIR.libXprintUtil?=	../../x11/libXprintUtil

.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # LIBXPRINTUTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libXprintUtil
