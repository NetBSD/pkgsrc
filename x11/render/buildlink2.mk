# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/19 16:33:57 wiz Exp $
#
# This Makefile fragment is included by packages that use render.
#

.if !defined(RENDER_BUILDLINK2_MK)
RENDER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			render
BUILDLINK_DEPENDS.render?=		render>=0.8
BUILDLINK_PKGSRCDIR.render?=		../../x11/render
# header files only
BUILDLINK_DEPMETHOD.render=		build

EVAL_PREFIX+=	BUILDLINK_PREFIX.render=render
BUILDLINK_PREFIX.render_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.render+=	include/X11/extensions/render.h
BUILDLINK_FILES.render+=	include/X11/extensions/renderproto.h
BUILDLINK_FILES.render+=	lib/pkgconfig/render.pc

BUILDLINK_TARGETS+=	render-buildlink

render-buildlink: _BUILDLINK_USE

.endif	# RENDER_BUILDLINK2_MK
