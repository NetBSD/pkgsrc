# $NetBSD: buildlink2.mk,v 1.3 2002/09/10 16:06:51 wiz Exp $

.if !defined(GTKHTML_BUILDLINK2_MK)
GTKHTML_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtkhtml
BUILDLINK_DEPENDS.gtkhtml?=		gtkhtml>=1.0.1nb2
BUILDLINK_PKGSRCDIR.gtkhtml?=		../../www/gtkhtml

EVAL_PREFIX+=			BUILDLINK_PREFIX.gtkhtml=gtkhtml
BUILDLINK_PREFIX.gtkhtml_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gtkhtml+=		include/gtkhtml/*
BUILDLINK_FILES.gtkhtml+=		lib/bonobo/libstorage_http.*
BUILDLINK_FILES.gtkhtml+=		lib/libgtkhtml.*

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../www/glibwww/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"
.include "../../x11/controlcenter/buildlink2.mk"

BUILDLINK_TARGETS+=		gtkhtml-buildlink

gtkhtml-buildlink: _BUILDLINK_USE

.endif	# GTKHTML_BUILDLINK2_MK
