# $NetBSD: buildlink3.mk,v 1.37 2024/11/01 00:54:19 wiz Exp $

BUILDLINK_TREE+=	libkactivities4

.if !defined(LIBKACTIVITIES4_BUILDLINK3_MK)
LIBKACTIVITIES4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkactivities4+=	libkactivities4>=4.7.95
BUILDLINK_ABI_DEPENDS.libkactivities4+=	libkactivities4>=4.13.3nb39
BUILDLINK_PKGSRCDIR.libkactivities4?=	../../x11/libkactivities4

.include "../../x11/kdelibs4/buildlink3.mk"
.endif # LIBKACTIVITIES4_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkactivities4
