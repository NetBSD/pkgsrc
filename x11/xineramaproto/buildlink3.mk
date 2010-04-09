# $NetBSD: buildlink3.mk,v 1.3 2010/04/09 08:36:30 tnn Exp $

BUILDLINK_DEPMETHOD.xineramaproto?=	build

BUILDLINK_TREE+=	xineramaproto

.if !defined(XINERAMAPROTO_BUILDLINK3_MK)
XINERAMAPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xineramaproto+=	xineramaproto>=1.2
BUILDLINK_PKGSRCDIR.xineramaproto?=	../../x11/xineramaproto

.include "../../x11/libX11/buildlink3.mk"
.endif # XINERAMAPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xineramaproto
