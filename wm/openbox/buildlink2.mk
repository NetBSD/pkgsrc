# $NetBSD: buildlink2.mk,v 1.1 2003/12/18 09:57:27 wiz Exp $
#
# This Makefile fragment is included by packages that use openbox.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(OPENBOX_BUILDLINK2_MK)
OPENBOX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			openbox
BUILDLINK_DEPENDS.openbox?=		openbox>=3.0
BUILDLINK_PKGSRCDIR.openbox?=		../../wm/openbox3

EVAL_PREFIX+=	BUILDLINK_PREFIX.openbox=openbox
BUILDLINK_PREFIX.openbox_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.openbox+=	include/openbox/3.0/openbox/*.h
BUILDLINK_FILES.openbox+=	lib/libobparser.*
BUILDLINK_FILES.openbox+=	lib/libobrender.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"

BUILDLINK_TARGETS+=	openbox-buildlink

openbox-buildlink: _BUILDLINK_USE

.endif	# OPENBOX_BUILDLINK2_MK
