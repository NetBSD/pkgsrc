# $NetBSD: buildlink3.mk,v 1.1 2025/05/05 08:05:10 tnn Exp $

BUILDLINK_TREE+=	libei

.if !defined(LIBEI_BUILDLINK3_MK)
LIBEI_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.libei+=	libei>=1.4.0
BUILDLINK_PKGSRCDIR.libei?=	../../x11/libei

.if defined(OPSYS_HAS_KQUEUE)
.include "../../devel/libepoll-shim/buildlink3.mk"
.endif
.endif	# LIBEI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libei
