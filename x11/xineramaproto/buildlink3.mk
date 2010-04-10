# $NetBSD: buildlink3.mk,v 1.4 2010/04/10 21:09:21 tnn Exp $

BUILDLINK_DEPMETHOD.xineramaproto?=	build

BUILDLINK_TREE+=	xineramaproto

.if !defined(XINERAMAPROTO_BUILDLINK3_MK)
XINERAMAPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xineramaproto+=	xineramaproto>=1.1.1
BUILDLINK_PKGSRCDIR.xineramaproto?=	../../x11/xineramaproto

.include "../../x11/libX11/buildlink3.mk"
.endif # XINERAMAPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xineramaproto
