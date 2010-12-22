# $NetBSD: buildlink3.mk,v 1.14 2010/12/22 23:41:30 abs Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	renderproto

.if !defined(RENDERPROTO_BUILDLINK3_MK)
RENDERPROTO_BUILDLINK3_MK:=

.if ${X11_TYPE} == "native"
. include "../../mk/x11.buildlink3.mk"
. if ${BUILTIN_X11_TYPE.native} == "XFree86"
RENDERPROTO_RENDERPROTO9=1
. endif
.endif

.if defined(RENDERPROTO_RENDERPROTO9)
BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.9.3nb1
BUILDLINK_PKGSRCDIR.renderproto?=	../../x11/renderproto9
.else
BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.9.3nb1
BUILDLINK_PKGSRCDIR.renderproto?=	../../x11/renderproto
.endif

BUILDLINK_DEPMETHOD.renderproto?=	build
.endif # RENDERPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-renderproto
