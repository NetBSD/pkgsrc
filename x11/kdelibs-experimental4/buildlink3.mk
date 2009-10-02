# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/02 19:23:22 markd Exp $

BUILDLINK_TREE+=	kdelibs-experimental4

.if !defined(KDELIBS_EXPERIMENTAL4_BUILDLINK3_MK)
KDELIBS_EXPERIMENTAL4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdelibs-experimental4+=	kdelibs-experimental4>=4.2.98
BUILDLINK_PKGSRCDIR.kdelibs-experimental4?=	../../x11/kdelibs-experimental4

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# KDELIBS_EXPERIMENTAL4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdelibs-experimental4
