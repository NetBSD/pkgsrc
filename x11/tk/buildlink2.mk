# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:56 jlam Exp $

.if !defined(TK_BUILDLINK2_MK)
TK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		tk
BUILDLINK_DEPENDS.tk?=		tk>=8.3.4
BUILDLINK_PKGSRCDIR.tk?=	../../x11/tk

EVAL_PREFIX+=			BUILDLINK_PREFIX.tk=tk
BUILDLINK_PREFIX.tk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tk=		include/tk.h
BUILDLINK_FILES.tk+=		include/tkDecls.h
BUILDLINK_FILES.tk+=		include/tkPlatDecls.h
BUILDLINK_FILES.tk+=		include/tkIntXlibDecls.h
BUILDLINK_FILES.tk+=		include/tk/*/*.h
BUILDLINK_FILES.tk+=		lib/libtk83.*
BUILDLINK_FILES.tk+=		lib/libtkstub83.*

.include "../../lang/tcl/buildlink2.mk"

BUILDLINK_TARGETS+=	tk-buildlink

tk-buildlink: _BUILDLINK_USE

.endif	# TK_BUILDLINK2_MK
