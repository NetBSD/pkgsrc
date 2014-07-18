# $NetBSD: buildlink3.mk,v 1.9 2014/07/18 05:25:42 obache Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "modular" && \
	!exists(${X11BASE}/lib/pkgconfig/fixesproto.pc) && \
	!exists(${X11BASE}/lib${LIBABISUFFIX}/pkgconfig/fixesproto.pc)
.include "../../x11/fixesproto4/buildlink3.mk"
.else

BUILDLINK_DEPMETHOD.fixesproto?=	build

BUILDLINK_TREE+=	fixesproto

.if !defined(FIXESPROTO_BUILDLINK3_MK)
FIXESPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4.0.0
BUILDLINK_PKGSRCDIR.fixesproto?=	../../x11/fixesproto

.  if !defined(USE_BUILTIN.fixesproto)
CHECK_BUILTIN.fixesproto:=	yes
.include "../../x11/fixesproto/builtin.mk"
CHECK_BUILTIN.fixesproto:=	no
.  endif

.  if !empty(USE_BUILTIN.fixesproto:M[Nn][Oo])
BUILDLINK_API_DEPENDS.xextproto+=	xextproto>=7.0.99.1
.  endif

.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # FIXESPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-fixesproto

.endif
